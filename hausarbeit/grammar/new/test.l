%{
#include <stdio.h>
#include <stdlib.h>

// include generated bison header
#include "test.tab.h"

%}

/* 
    patterns can be described here
*/

SEL_STRING			[a-zA-Z0-9]+

%%
%{
/*
    rules for pattern recognition
*/
%}

[ \t\n]             ;   // ignore whitespace
[0-9]+\.[0-9]+      { yylval.fval = atof(yytext); return FLOAT; }
[0-9]+              { yylval.ival = atoi(yytext); return INT; }
{SEL_STRING}        	{ yylval.sval = strdup(yytext); return STRING; }
.                   ;   // ignore everything else

%%

/*
    user code, lexen etc.
    moved to test.bison
*/
