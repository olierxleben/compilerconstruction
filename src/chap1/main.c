#include "util.h"
#include "slp.h"
#include "prog1.h"
#include "prog2.h"
#include "table.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int maxargs(A_stm stm);
int printStmCount(A_expList exps);
void checkExp(A_exp exp);

struct IntAndTable{int i; Table_ t;};
void interp(A_stm stm);
Table_ interpStm(A_stm s, Table_ t);
struct IntAndTable interpExp(A_exp e, Table_ t);
Table_ update(Table_ t, string id, int value);
int lookup(Table_ t, string key);


int main(int argc, char** argv){
    
    printf("max args of prog1: %d\n", maxargs(prog()));
    printf("max args of prog2: %d\n", maxargs(prog2()));
    interp(prog2());
    return 0;
}

int maxargs(A_stm stm){
    static int max = 0;
    int tmp = 0;
    switch(stm->kind){
        case A_printStm:
            tmp = printStmCount(stm->u.print.exps);
            max = max <= tmp ? tmp : max;
            break;
        case A_compoundStm:
            maxargs(stm->u.compound.stm1);
            maxargs(stm->u.compound.stm2);
            break;
        case A_assignStm:
            checkExp(stm->u.assign.exp);
            break;
        default:
            break;
    }
    return max;
}

void checkExp(A_exp exp){
    if(exp->kind == A_eseqExp){
        maxargs(exp->u.eseq.stm);
        checkExp(exp->u.eseq.exp);
    }
}

int printStmCount(A_expList exps){
    int cnt=0;
    
    switch(exps->kind){
        case A_pairExpList:
            checkExp(exps->u.pair.head);
            cnt++;
            cnt+=printStmCount(exps->u.pair.tail);         
            break;
         case A_lastExpList:
            checkExp(exps->u.last);
            cnt++;
            break;
    }
    
    return cnt;
}

void interp(A_stm stm){
    Table_ t = NULL;
    t = interpStm(stm, t);
    while(t != NULL){
        printf("%s: %d\n", t->id, t->value);    
        t = t->tail;
    }
}

struct IntAndTable interpExpList(A_expList e, Table_ t){
    struct IntAndTable ret;
    Table_ tmp = NULL;
    switch(e->kind){
        case A_pairExpList:         
            ret = interpExp(e->u.pair.head, t);   
            tmp = update(ret.t, "print", ret.i);
            ret = interpExpList(e->u.pair.tail, tmp);
            return ret;
            
        case A_lastExpList:
            ret = interpExp(e->u.last, t);
            return ret;
    }
}

Table_ interpStm(A_stm s, Table_ t){
    struct IntAndTable tmp; 
    Table_ ret = NULL;
    int i = 0;
    
    switch(s->kind){
        case A_compoundStm:
            ret = interpStm(s->u.compound.stm1, t);
            ret = interpStm(s->u.compound.stm2, ret);
            break;
        case A_assignStm:
            tmp = interpExp(s->u.assign.exp, t);
            ret = update(tmp.t, s->u.assign.id, tmp.i);
            break;
        case A_printStm:
            tmp = interpExpList(s->u.print.exps, t);
            ret = update(tmp.t, "print", tmp.i);
            //t = update(tmp.t, t->id, tmp.i);
            break;
    }
    return ret;
}

int operation(A_binop op, int left, int right){
    switch(op){
        case A_plus:
            return left + right;
        case A_minus:
            return left - right;
        case A_times:
            return left * right;
        case A_div:
            return left / right;
    }
}

struct IntAndTable interpExp(A_exp e, Table_ t){
    Table_ tmp = NULL; 
    struct IntAndTable left;
    struct IntAndTable right;
    struct IntAndTable ret;
    int val = 0;
    switch(e->kind){
        case A_idExp:
            ret.i = lookup(t, e->u.id);    
            ret.t = t;
            return ret;
        case A_numExp:
            ret.i = e->u.num;
            ret.t = t;
            return ret;
        case A_opExp:
            left = interpExp(e->u.op.left, t);
            right = interpExp(e->u.op.right, left.t);
            val = operation(e->u.op.oper, left.i, right.i);
            ret.i = val;
            ret.t = right.t;
            return ret;
        case A_eseqExp:
            tmp = interpStm(e->u.eseq.stm, t);
            return interpExp(e->u.eseq.exp, tmp);
            break;      
    }
}

Table_ update(Table_ t, string id, int value){
    Table_ tmp = Table(id, value, t);
    return tmp;
}

int lookup(Table_ t, string key) {
    if(t == NULL){
        printf("lookup Error!\n");
        exit(1);
    }
    if( strcmp(t->id, key) == 0) {
        return t->value;
    }
    return lookup(t->tail, key);
}
