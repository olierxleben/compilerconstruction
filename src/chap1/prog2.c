// prog2: another example for a straight-line program
// M. Weinhardt, 19.02.13

#include "util.h"
#include "slp.h"
#include "prog2.h"

A_stm prog2(void) {
// prg2: a:=8/3; b:=(print((print(a,a-1),10*a),a-50); print(b)
//
// Expected results:
// - Maximum print argument number: 2
// - Interpreter output:
//    2 1
//    20
//    -48
//
return 
 A_CompoundStm(A_AssignStm("a",
                 A_OpExp(A_NumExp(8), A_div, A_NumExp(3))),
  A_CompoundStm(A_AssignStm("b",
		 A_EseqExp(A_PrintStm(
                  A_LastExpList(
                   A_EseqExp(A_PrintStm(
			      A_PairExpList(A_IdExp("a"),
					    A_LastExpList(
					     A_OpExp(A_IdExp("a"), A_minus, A_NumExp(1))))), 
			     A_OpExp(A_NumExp(10), A_times, A_IdExp("a"))))),
			   A_OpExp(A_IdExp("a"), A_minus, A_NumExp(50)))),
		A_PrintStm(A_LastExpList(A_IdExp("b")))));
}
