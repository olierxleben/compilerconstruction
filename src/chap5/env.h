/* Copyright (c) 1997 Andrew W. Appel.  Licensed software: see LICENSE file */
/*
 * env.h - Environment data structures for type checking, etc.
 *
 * All types and functions declared in this header file begin with "E_"
 * Linked list types end with "..list"
 */
#ifndef ENV_H
#define ENV_H
typedef struct E_enventry_ *E_enventry;
typedef struct E_envList_ *E_envList;

struct E_enventry_ {
    enum { E_varEntry, E_funEntry } kind;
    union {
	struct {
	    Ty_ty ty;
	} var;
	struct {
	    Ty_tyList formals;
	    Ty_ty result;
	} fun;
    } u;
};

struct E_envList_ {
    E_enventry head;
    E_envList tail;
};

E_enventry E_VarEntry (Ty_ty ty);
E_enventry E_FunEntry (Ty_tyList formals, Ty_ty result);

S_table E_base_tenv (void);	/* Ty_ty environment */
S_table E_base_env (void);	/* E_enventry environment */

E_envList E_EnvList (E_enventry head, E_envList tail);

void E_print (void *value);
#endif
