%{
    #include <stdio.h>
    #include <stdlib.h>
	#include <ncurses.h>
	#include <string.h>
    #include "css_types.h"
    #include "css.tab.h"
    #include "parsecss.h"
        
    css_RuleList root; 
	
    extern int yyparse();
    extern FILE *yyin;
    
    void yyerror(const char *s);
	#define BUFFER_SIZE 4096
	
%}

// types which are found/returned by flex 
%union{
    char* sval;
    css_Selector aSelector;
    css_Declaration aDeclaration;
	css_SelectorList aSelectorList;
	css_DeclarationList aDeclarationList;
	css_Rule aRule;
	css_RuleList aRuleList;
}


// Terminal symbols of our language
%token <sval> STRING

%token LBRACE RBRACE COMMA DOT SEMICOLON COLON

%type <aRuleList> rulelist css
%type <aRule> rule
%type <aDeclarationList> declarationlist
%type <aDeclaration> declaration
%type <aSelectorList> selectorlist
%type <aSelector> selector

%%
// grammar section, parsing rules

css:				rulelist {$$ = root = $1;}
	;

rulelist: 			rule rulelist { $$ = create_CSSRuleList($1,$2); }
		  			| rule { $$ = create_CSSRuleList($1,NULL); }
	;
rule:				selectorlist LBRACE declarationlist RBRACE {$$ = create_CSSRule($1, $3); }
	;
selectorlist:		selector COMMA selectorlist { $$ = create_CSSSelectorList($1,$3);}
					| selector { $$ = create_CSSSelectorList($1, NULL);}
	;			
selector:			STRING { $$ = create_CSSSelector($1); }
					| STRING COLON STRING { char buffer[256] = {0}; strcat(buffer, $1); strcat(buffer, ":"); strcat(buffer, $3);  $$ = create_CSSSelector(strdup(buffer)); }
	;
declarationlist: 	declaration SEMICOLON declarationlist { $$ = create_CSSDeclarationList($1,$3);}
					| declaration SEMICOLON { $$ = create_CSSDeclarationList($1, NULL);}
					| declaration { $$ = create_CSSDeclarationList($1, NULL);}
	;				
declaration:		STRING COLON STRING { $$ = create_CSSDeclaration($1, $3); }
					| STRING COLON STRING COMMA STRING COMMA STRING { 
						 char buffer[BUFFER_SIZE] = {0}; strcat(buffer, $3); strcat(buffer, ","); strcat(buffer, $5); strcat(buffer, ","); strcat(buffer, $7);
						 $$ = create_CSSDeclaration($1, strdup(buffer)); }
					| STRING COLON STRING COMMA STRING COMMA STRING COMMA STRING { 
						 char buffer[BUFFER_SIZE] = {0}; strcat(buffer, $3); strcat(buffer, ","); strcat(buffer, $5); strcat(buffer, ","); strcat(buffer, $7);
						 strcat(buffer, ","); strcat(buffer, $9); 
						 $$ = create_CSSDeclaration($1, strdup(buffer)); }
	;

%%
// user code section

css_RuleList parseCSS(char* fileName) {
    // set inputfile
    FILE *inFile = fopen(fileName, "r");
    if(!inFile) {
        printf("Could not open input file!\n");
        exit(-1);
    }
    yyin = inFile;
   
    // flex version
    //yylex();
    
    // bison: parse until there is no input anymore
    do {
        yyparse();
    } while(!feof(yyin));
   	
    return root;
}


void yyerror(const char *s) {
    printf("EEK, parse error! Message: %s\n", s);
    exit(-1);
}
