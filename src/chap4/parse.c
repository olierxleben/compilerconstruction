/*
 * parse.c - Parse source file.
 * Adapted M. Weinhardt, 28.02.13
 */

#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "symbol.h"
#include "absyn.h"
#include "errormsg.h"
#include "parse.h"
#include "prabsyn.h"

extern int yyparse(void);
extern A_exp absyn_root;

/* parse source file fname; 
   return abstract syntax data structure */
A_exp parse(string fname) 
{EM_reset(fname);
 if (yyparse() == 0) /* parsing worked */
   return absyn_root;
 else return NULL;
}

int main(int argc, char **argv) {
 FILE* outfile;
 A_exp ast;
 if (argc!=3) {fprintf(stderr,"usage: parser tigfile outfile\n"); exit(1);}
 if (! (outfile=fopen(argv[2], "w"))) exit(1);
 EM_reset(argv[1]);
 ast = parse(argv[1]);
 if (ast)
   pr_exp(outfile, ast, 0);
 return 0;
}
