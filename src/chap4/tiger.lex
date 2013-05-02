 /**
 * TODO: \f___f\ negative literals -32
 **/
%{
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "util.h"
//#include "tokens.h"
#include "symbol.h"
#include "absyn.h"
#include "y.tab.h"
#include "errormsg.h"

int charPos=1;
int commentNesting = 0; // comment nested counter
int forfeed = 0;
int modus = 0;

char buffer[256];

int yywrap(void)
{
 charPos=1;
 return 1;
}


void adjust(void)
{
 EM_tokPos=charPos;
 charPos+=yyleng;
}

%}

%x COMMENT
%x _STRING
%x FORFEED

%% /* initial */

\r\n {adjust(); EM_newline(); continue;}
[ \r\t] {adjust(); continue;}
\n {adjust(); EM_newline(); continue;}
"," { adjust(); return COMMA;}
":" { adjust(); return COLON;}
";" { adjust(); return SEMICOLON;}
"(" { adjust(); return LPAREN;}
")" { adjust(); return RPAREN;}
"[" { adjust(); return LBRACK ;}
"]" { adjust(); return RBRACK ;}
"{" { adjust(); return LBRACE ;}
"}" { adjust(); return RBRACE ;}
"." { adjust(); return DOT ;}
"+" { adjust(); return PLUS ;}
"-" { adjust(); return MINUS ;}
"*" { adjust(); return TIMES ;}
"/" { adjust(); return DIVIDE ;}
"=" { adjust(); return EQ ;}
"<>" { adjust(); return NEQ ;}
"<" { adjust(); return LT ;}
"<=" { adjust(); return LE ;}
">" { adjust(); return GT ;}
">=" { adjust(); return GE ;}
"&" { adjust(); return AND ;}
"|" { adjust(); return OR ;}
":=" { adjust(); return ASSIGN ;}

array { adjust(); return ARRAY ;}
if { adjust(); return IF;}
then { adjust(); return THEN ;}
else { adjust(); return ELSE ;}
while { adjust(); return WHILE ;}
for { adjust(); return FOR;}
to { adjust(); return TO ;}
do { adjust(); return DO ;}
let { adjust(); return LET;}
in { adjust(); return IN ;}
end { adjust(); return END ;}
of { adjust(); return OF ;}
break { adjust(); return BREAK ;}
nil { adjust(); return NIL ;}
function { adjust(); return FUNCTION ;}
var { adjust(); return VAR ;}
type { adjust(); return TYPE ;}

[a-zA-Z][_a-zA-Z0-9]* { adjust(); yylval.sval=yytext; return ID;}

[0-9]+ { adjust(); yylval.ival=atoi(yytext); return INT;}

\" {
    adjust();
    buffer[0] = '\0';
    BEGIN(_STRING);
}

"/*" {
      adjust();
      commentNesting++;
      yylval.sval=yytext;
      modus = 2;
      BEGIN(COMMENT);
     }

"*/" {
       adjust();
       EM_error(EM_tokPos, "oops! you closed a comment without opening it.");
       yyterminate();
     }

<<EOF>> {
    if(modus == 1){
      EM_error(EM_tokPos, "oops! Didn't close forefeed.");
    } else if(modus == 2) {
      EM_error(EM_tokPos, "oops! Didn't close Comment.");
    }
    yyterminate();
}
     
  /* all the rest */
. { EM_error(EM_tokPos,"illegal token");}

<FORFEED>{
    f\\ {
      modus = 0;
      BEGIN(_STRING);      
    }

    . {continue;}
}

<_STRING>{
    \\f {
        modus = 1;
        BEGIN(FORFEED);
    }
    
    \\n {
        adjust();
        strcat(buffer, "\n");
    }
    
    \\t {
        adjust();
        strcat(buffer, "\t");
    }
    
    \\[0-9][0-9][0-9] {
      adjust();
      char ch[2];
      ch[0]= (char) atoi(yytext+1);
      ch[1] = '\0';
      strcat(buffer, ch);
    }
    
    \\\\ {

        adjust();
        strcat(buffer, "\\");
    }
    
    \\\" {
        adjust();
        strcat(buffer, "\"");
    }
    
    \" {
        BEGIN(INITIAL);
        strcat(buffer, "\0");
        yylval.sval = buffer;
        return STRING;
    }
    
    .$ { 
        if(*(yytext)=='\"'){
          BEGIN(INITIAL);
          strcat(buffer, "\0");
          yylval.sval = buffer;
          return STRING;
          }
        EM_error(EM_tokPos, "oops! Missing \"");
        yyterminate();
    }
    . {
        adjust();
        strcat(buffer, yytext);
      }
}

  /* Nested Rulesets for comments */
<COMMENT>{
 /* increment nesting if another comment opened */
"/*" {
adjust();
commentNesting++;
//continue;
};

 /* decrement nesting and exit the ruleset back to the initial */
"*/" {
adjust();
commentNesting--;
if (commentNesting == 0) {
    yylval.sval=yytext;
    modus = 0;
    BEGIN(INITIAL);
}
};

 /* something in the comment, should make sense to the reader ;) */
. { adjust(); }
}
