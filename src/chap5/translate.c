/* Copyright (c) 1997 Andrew W. Appel.  Licensed software: see LICENSE file */
/*
 * translate.c 
 *
 */
#include <stdio.h>
#include <string.h>
#include "util.h"
#include "errormsg.h"
#include "symbol.h"
#include "absyn.h"
#include "translate.h"

Tr_expList
Tr_ExpList (Tr_exp exp, Tr_expList expList)
{
  Tr_expList e = checked_malloc (sizeof (*e));
  e->head = exp;
  e->tail = expList;
  return e;
}

