/* Copyright (c) 1997 Andrew W. Appel.  Licensed software: see LICENSE file */
/*
 * env.c - Functions to create environment data structures.
 *
 * All types and functions declared in this file begin with "E_"
 * Linked list types end with "..list"
 */
#include <stdio.h>
#include "util.h"
#include "symbol.h"
#include "absyn.h"
#include "types.h"
#include "types.h"
#include "translate.h"
#include "env.h"

E_enventry
E_VarEntry (Ty_ty ty)
{
  E_enventry p = checked_malloc (sizeof (*p));

  p->kind = E_varEntry;
  p->u.var.ty = ty;
  return p;
}

E_enventry
E_FunEntry (Ty_tyList formals, Ty_ty result)
{
  E_enventry p = checked_malloc (sizeof (*p));

  p->kind = E_funEntry;
  p->u.fun.formals = formals;
  p->u.fun.result = result;
  return p;
}

E_envList
E_EnvList (E_enventry head, E_envList tail)
{
  E_envList p = checked_malloc (sizeof (*p));

  p->head = head;
  p->tail = tail;
  return p;
}

/* mappings for the "base" or "predefined" type environment: 
   int & string.
   using NULL because we haven't defined Tr_level yet.
 */
S_table
E_base_tenv (void)
{
  S_table env = S_empty ();

  S_enter (env, S_Symbol ("int"), (void *) Ty_Int ());
  S_enter (env, S_Symbol ("string"), (void *) Ty_String ());
  return env;
}

static void
mkfun (S_table env, string name, Ty_tyList formals, Ty_ty result)
{
  S_enter (env, S_Symbol (name), (void *) E_FunEntry (formals, result));
}

S_table
E_base_env (void)
{
  S_table env = S_empty ();

  mkfun (env, "print", Ty_TyList (Ty_String (), NULL), Ty_Void ());
  mkfun (env, "flush", NULL, Ty_Void ());
  mkfun (env, "ord", Ty_TyList (Ty_String (), NULL), Ty_Int ());
  mkfun (env, "chr", Ty_TyList (Ty_Int (), NULL), Ty_String ());
  mkfun (env, "size", Ty_TyList (Ty_String (), NULL), Ty_Int ());
  mkfun (env, "substring", Ty_TyList (Ty_String (),
				      Ty_TyList (Ty_Int (),
						 Ty_TyList (Ty_Int (),
							    NULL))),
	 Ty_String ());
  mkfun (env, "concat",
	 Ty_TyList (Ty_String (), Ty_TyList (Ty_String (), NULL)),
	 Ty_String ());
  mkfun (env, "not", Ty_TyList (Ty_Int (), NULL), Ty_Int ());
  mkfun (env, "getchar", NULL, Ty_String ());
  return env;
}

void
E_print (void *value)
{
  E_enventry ee = (E_enventry) value;

  switch (ee->kind)
    {
    case E_varEntry:
      /* printf ("E_varEntry(%s, ",
         ee->u.var.access == NULL ? "null" : "not null"); */
      Ty_print (ee->u.var.ty);
      printf (")");
      break;
    case E_funEntry:
      /* printf ("E_funEntry(%s, %s, ",
         ee->u.fun.level == NULL ? "null" : "not null",
         ee->u.fun.label ==
         NULL ? "null" : S_name (ee->u.fun.label)); */
      TyList_print (ee->u.fun.formals);
      printf (", ");
      Ty_print (ee->u.fun.result);
      printf (")");
      break;
    }
}
