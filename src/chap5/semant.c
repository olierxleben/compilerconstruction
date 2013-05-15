/* Copyright (c) 1997 Andrew W. Appel.  Licensed software: see LICENSE file */
/*
 * semant.c - Functions to create user-defined environment data structures.
 * Adapted M. Weinhardt 25.03.13
*
 */
#include <stdio.h>
#include "util.h"
#include "symbol.h"
#include "absyn.h"		/* defines A_pos */
#include "types.h"
#include "translate.h"
#include "env.h"
#include "errormsg.h"
#include "semant.h"

static struct expty transExp (S_table env, S_table tenv, A_exp a);
static Tr_exp transDec (S_table env, S_table tenv, A_dec dec);
static Ty_tyList makeFormalTyList(S_table tenv, A_fieldList params);
static E_envList makefundecList(S_table env, S_table tenv, A_fundecList fList);

// global flag for checking break statements:
static int in_loop;

struct expty
{
  Tr_exp exp;
  Ty_ty ty;
};


static struct expty
expTy (Tr_exp exp, Ty_ty ty)
{
   struct expty e;
   e.exp = exp;
   e.ty = ty;
   return e;
}

/* Finds a symbol in the type "env" table and returns its "name"bv type */
static Ty_ty tylook (S_table env, S_symbol id, A_pos pos) {
  Ty_ty t = S_look(env, id);
  if (!t)
    EM_error(pos, "type %s not in scope.", S_name(id));
 return t; 
}

/* returns the actual type of an expression */
static Ty_ty actual_ty (Ty_ty ty) {
  if (ty->kind==Ty_name)
    return actual_ty(ty->u.name.ty);
  else
    return ty;
}

/* translates a fieldlist into a typefieldlist */
static Ty_fieldList transfieldList (S_table tenv, A_fieldList fl) {
  if (!fl)
    return NULL;
  
  Ty_field tf = Ty_Field(fl->head->name, tylook(tenv, fl->head->typ, fl->head->pos));
  return Ty_FieldList(tf, transfieldList(tenv, fl->tail)); // recur
}

/***********************************************************************
* check and translate types
*/
static Ty_ty transTy (S_table tenv, A_ty t)
{
  switch (t->kind) {
  case A_nameTy: 
    return tylook(tenv, t->u.name, t->pos);
  case A_recordTy:
    return Ty_Record(transfieldList(tenv, t->u.record));
  case A_arrayTy:
    return Ty_Array(tylook(tenv, t->u.array, t->pos));
    break;
  default:
    assert(0);
  }
  return NULL;
}

/*************************************************************************
* functions for recursive declarations:
*/
    
/* Create a "name" type with no actual type */
/* Enter the "name" type with an empty header and no body */
static Ty_tyList
makenametyList (S_table tenv, A_nametyList tyl) {
   Ty_tyList ttl = NULL, ttl2, ttlend; // list to return
   Ty_ty tt; // new (incomplete) type
   while (tyl) {
     tt = Ty_Name(tyl->head->name, NULL);
     ttlend = Ty_TyList(tt, NULL); // create new tylist element
     if (!ttl) {
       ttl = ttlend;
       ttl2 = ttlend;
     }
     else {
	ttl2->tail = ttlend; // add to end of list
        ttl2 = ttlend;
     }
     S_enter(tenv, tyl->head->name, tt); // add to tenv
     tyl = tyl->tail;
    }
   return ttl;
}

/* Then fill in the actual type */
static void
transnametyList (S_table tenv, A_nametyList a_tyl, Ty_tyList tyl) {
  Ty_ty tt;
  while (a_tyl) { // iterate over a_tyl and tyl
    tt = transTy(tenv, a_tyl->head->ty); // transform first body in a_tyl
    assert(tyl->head->kind == Ty_name);
    tyl->head->u.name.ty = tt; // replace NULL in type list
    a_tyl = a_tyl->tail;
    tyl = tyl->tail;
  }
}

/* first pass: process headers of functions */
static E_envList
makefundecList (S_table env, S_table tenv, A_fundecList fList) {
  if (!fList)
    return NULL;
  
  A_fundec f = fList->head;
  Ty_ty resultTy;
  if (f->result)
    resultTy = S_look(tenv, f->result);
  else
    resultTy = Ty_Void();
  Ty_tyList formalTys = makeFormalTyList(tenv, f->params);
  E_enventry funent = E_FunEntry(formalTys, resultTy);
  S_enter(env, f->name, funent);
  return E_EnvList(funent, makefundecList(env, tenv, fList->tail));
}

/* second pass: process bodies of functions */
/* a type mismatch below means the return value does not match type of
 * body's expression. */
static void
transfundecList (S_table env, S_table tenv, E_envList eList, A_fundecList fList) {
  while (fList) {
    A_fundec f = fList->head;
    E_enventry funent = eList->head;
    S_beginScope(env);
    { A_fieldList l; Ty_tyList t;
       for (l = f->params, t=funent->u.fun.formals; l; l=l->tail, t=t->tail) {
	 if (!t->head)
	   assert(0);
	 S_enter(env, l->head->name, E_VarEntry(t->head));
        }
     }
     assert(f->body);
     struct expty ty = transExp(env, tenv, f->body);
     Ty_ty bodytyp = actual_ty(funent->u.fun.result);
     if (ty.ty != bodytyp) {
       EM_error(f->pos, "Function %s body's result type differs from declaration.",
                    S_name(f->name));
     }
     S_endScope(env);
     fList = fList->tail;
     eList = eList->tail;
  }
}

/************************************************************************* 
* Take an abstract syntax representation of a var and make sure it has an
 * "actual" type. If it does create a "struct expty" which consists of aList *
 * pair: "Tr_exp" and "ty."
 */
static struct expty transVar (S_table env, S_table tenv, A_var v)
{
  struct expty ty;
  switch(v->kind) {
  case A_simpleVar: {
    E_enventry x = S_look(env, v->u.simple);
    if (x && x->kind==E_varEntry)
      ty = expTy(NULL, actual_ty(x->u.var.ty));
    else {
      EM_error(v->pos, "undefined variable %s", S_name(v->u.simple));
      ty = expTy(NULL, Ty_Int());
    }
    assert(ty.ty);
    break;
  }
  case A_fieldVar:  {
    struct expty expty2 = transVar(env, tenv, v->u.field.var);
    Ty_ty basety = actual_ty(expty2.ty);
    ty = expTy(NULL, Ty_Void());
    if (basety->kind != Ty_record)
	EM_error(v->pos, "access to field of non-record base type.");
    else {
          Ty_fieldList tfl = basety->u.record;
	  int flag = 0;
	  while (tfl && !flag) { // search field in definition
            if (tfl->head->name == v->u.field.sym) {
	      flag = 1;
	      ty = expTy(NULL, tfl->head->ty);
	    }
	    tfl = tfl->tail;
          }
	  if (!flag) {
	    EM_error(v->pos, "record field %s does not exist.", S_name(v->u.field.sym));
	  }
      }
      assert(ty.ty);
    break;
  }
  case A_subscriptVar: {
    struct expty expty2 = transVar(env, tenv, v->u.subscript.var);
    Ty_ty basety = actual_ty(expty2.ty);
    if (basety->kind == Ty_array) {
      Ty_ty resultty = basety->u.array;
      ty = expTy(NULL, resultty);
    }
    else
      ty = expTy(NULL, Ty_Void()); // dummy
    
    struct expty indext = transExp(env, tenv, v->u.subscript.exp);
    if (indext.ty->kind != Ty_int)
      EM_error(v->pos, "array subscript must be integer.");
    assert(ty.ty);
    break;
  }	  
  }
  return ty;
}

/* Makes sure that the list of actual and formal parameters match */
static Tr_expList matchParams (S_table env, S_table tenv, Ty_tyList formals, A_expList actuals,
					    A_pos pos) {
	while (formals) { // iterate over both lists
	  if (!actuals) {
            EM_error(pos, "More formal than actual parameters.");
	    break;
	  }
          struct expty actual = transExp(env, tenv, actuals->head);
	   Ty_ty actty = actual_ty(actual.ty);
           Ty_ty formal = actual_ty(formals->head);
	  if (formal != actty &&
	      (formal->kind != Ty_record || actty->kind != Ty_nil)) {
	    EM_error(actuals->head->pos, "Formal does not match actual parameter");
          }
	  formals = formals->tail;
	  actuals = actuals->tail;
        }
	if (actuals) // more actuals then formals!
          EM_error(actuals->head->pos, "More actual than formal parameters");
	return NULL;
}

/* Check if the defined record fields and the field list in the initialization matches */
static void matchFieldlist(S_table env, S_table tenv, Ty_fieldList recfields, A_efieldList initfields) {
  struct expty ty;
  while (recfields) {
    if (!initfields) {
      EM_error(0, "Record field \"%s\" has not been initialized",
      S_name(recfields->head->name));
      recfields = recfields->tail;
      continue;
    }

    if (recfields->head->name != initfields->head->name) {
      EM_error(initfields->head->exp->pos, "Field name mismatch in record initialization.");
      break; // don't check remaining fields
    }
    else {
      ty = transExp(env, tenv, initfields->head->exp);
      Ty_ty fieldty = actual_ty(recfields->head->ty);
      Ty_ty initty = actual_ty(ty.ty);
      if (fieldty != initty && (fieldty->kind != Ty_record  || initty->kind != Ty_nil)) {
        EM_error(initfields->head->exp->pos,
                     "Type mismatch in record field %s initialization",
		     S_name(initfields->head->name));
      }
    }
    recfields=recfields->tail;
    initfields=initfields->tail;
  }
}

/**************************************************************************
 * Take an abstract syntax representation of an exp and recursively compute its
 * type. Replace a named type by its actual type using fct. "actual_ty".
 * Use fct. "tylook" to lookup types in tenv if required.
 * Create and return a "struct expty" which consists of a pair: "Tr_exp" and "ty."
*/
static struct expty transExp (S_table env, S_table tenv, A_exp e) {
  struct expty ty = expTy(NULL, Ty_Void()); // dummy for error case
	
  /* COMPLETE CASE STATEMENTS FOR ALL EXPRESSION KINDS */
  switch (e->kind) {
  case A_nilExp: /* example for NIL given */
    ty = expTy(NULL, Ty_Nil()); break;
  case A_varExp:
    break;
  case A_intExp:
    break;
 case A_stringExp:
    break;
 case A_callExp: {
    /* Hint: Find funEntry with "S_look" in env and match its formals with the
	       function arguments using "matchParams". Set ty correctly.*/
    break;
  }
 case A_opExp: {
    break;
  }
  case A_recordExp: {
    /* Hint: Find record type in tenv, get its actual type and match its field list
                  with the record expression's field list using "matchFieldlist". */
    break;
  }
  case A_seqExp: {
    break;
  }
  case A_assignExp: {
    break;
  }
  case A_ifExp: {
    break;
  }
  case A_whileExp: {
    break;
  }
  case A_breakExp: 
    break;
  case A_forExp: {
    /* Hint: Type-check for expression. Process body in new scope for env which
                  also contains new loop var. */
    break;
  }
  case A_letExp: {
    /* Hint: Begin new scopes for env and tenv and process all declarations and
                 let-body in new scopes. */
    break;
  }
  case A_arrayExp: {
    /* Hint: Find array type in tenv and check array initialization. */
    break;
  }
  default:
    assert(0);
  }
  return ty;
}

// generate type list from parameters of a function
static Ty_tyList makeFormalTyList(S_table tenv, A_fieldList params) {
  if (!params)
    return NULL;
  Ty_ty firstty = tylook(tenv, params->head->typ, params->head->pos);
  if (params->tail)
    return Ty_TyList(firstty, makeFormalTyList(tenv, params->tail));
  else
    return Ty_TyList(firstty, NULL);
}

/**************************************************************************
 * check and translate declarations
*/
static Tr_exp transDec (S_table env, S_table tenv, A_dec dec) {
  switch (dec->kind) {
  case A_varDec: {
    struct expty e = transExp(env, tenv, dec->u.var.init);
    assert(e.ty);
    S_enter(env, dec->u.var.var, E_VarEntry(e.ty));
    if (dec->u.var.typ) { // check type
      Ty_ty typ = actual_ty(S_look(tenv, dec->u.var.typ));
      if (!typ)
        EM_error(dec->u.var.init->pos, "undefined type %s in variable declaration.",
			S_name(dec->u.var.typ));
      else if (typ != e.ty && (typ->kind != Ty_record || e.ty->kind != Ty_nil)) {
        EM_error(dec->u.var.init->pos, "Type mismatch at variable %s initialization.",
			S_name(dec->u.var.var));
      }
    }
    else if (e.ty == Ty_nil) { // no type, initialization with NIL not allowed!
	EM_error(dec->u.var.init->pos, "Nil-initialized record must have type.");
    }
    break;
  }
  case A_typeDec: {
    A_nametyList ntl = dec->u.type;
    Ty_tyList tyl = makenametyList(tenv, ntl);
    transnametyList (tenv, ntl, tyl);
    break;
  }
  case A_functionDec: {
    A_fundecList fdl = dec->u.function;
    E_envList envl = makefundecList (env, tenv, fdl);
    transfundecList (env, tenv, envl, fdl);
    break;
  }
  }
  return NULL;
}

void
SEM_transProg (A_exp exp)
{
  in_loop = 0; // not in loop!
  transExp (E_base_env (), E_base_tenv (), exp); 
}
