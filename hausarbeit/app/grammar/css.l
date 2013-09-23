%{
#include <stdio.h>
#include <stdlib.h>

// include generated bison header
#include "css_types.h"
#include "css.tab.h"

%}

%option noyywrap

/* 
    patterns can be described here
*/

SEL_STRING			["#"|"."]*[a-zA-Z0-9"#""("")"" "".""/"\-"%"\[\]"*""_""=""!""@""'""?"]+
RCHEVRON			">"
PLUS				"+"

%x COMMENT

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

[ \t\n\r]             ;   // ignore whitespace

{SEL_STRING}[ ]{RCHEVRON}[ ]{SEL_STRING}	{ yylval.sval = strdup(yytext); return STRING; }
{SEL_STRING}[ ]{PLUS}[ ]{SEL_STRING}	{ yylval.sval = strdup(yytext); return STRING; }
{SEL_STRING} {yylval.sval = strdup(yytext); return STRING; }

.                   ;   // ignore everything else

%%

/*
    user code, lexen etc.
    moved to test.bison
*/
