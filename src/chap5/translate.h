/* Copyright (c) 1997 Andrew W. Appel.  Licensed software: see LICENSE file */
/*
 * translate.h 
 *
 * All types and functions declared in this file begin with Tr_"
 * Linked list types end with "..list"
 */
#ifndef TRANSLATE_H
#define TRANSLATE_H
typedef struct Tr_accessList_ *Tr_accessList;
typedef struct Tr_access_ *Tr_access;
struct Tr_accessList_ {
    Tr_access head;
    Tr_accessList tail;
};
Tr_accessList Tr_AccessList (Tr_access head, Tr_accessList tail);

typedef void *Tr_exp;
typedef struct Tr_expList_ *Tr_expList;
struct Tr_expList_ {
    Tr_exp head;
    Tr_expList tail;
};
Tr_expList Tr_ExpList(Tr_exp head, Tr_expList tail);
#endif
