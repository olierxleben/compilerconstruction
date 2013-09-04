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


"," { return COMMA;}
":" { return COLON;}
";" { return SEMICOLON;}
"{" { return LBRACE ;}
"}" { return RBRACE ;}
"." { return DOT ;}

[ \t\n]             ;   // ignore whitespace
{SEL_STRING}        	{ yylval.sval = strdup(yytext); return STRING; }
.                   ;   // ignore everything else
%%

/*
    user code, lexen etc.
    moved to test.bison
*/
