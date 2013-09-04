%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "css_types.h"
    
    extern int yylex();
    extern int yyparse();
    extern FILE *yyin;
    
    void yyerror(const char *s);
    
    css_RuleList root;
%}

// types which are found/returned by flex 
%union {
    char *sval;
    css_Selector aSelector;
	css_Declaration aDeclaration;
	css_SelectorList aSelectorList;
	css_DeclarationList aDeclarationList;
	css_Rule aRule;
	css_RuleList ruleList;
}


// Terminal symbols of our language
%token <sval> STRING

%token LBRACE RBRACE COMMA DOT SEMICOLON COLON

%type <ruleList> rulelist css
%type <aRule> rule
%type <aDeclarationList> declarationlist
%type <aDeclaration> declaration
%type <aSelectorList> selectorlist
%type <aSelector> selector


%%
// grammar section, parsing rules

css:				rulelist  {$$ = root = $1;}
	;

rulelist: 			rule rulelist { $$ = createCSSRuleList($1,$2); }
		  			| rule { $$ = createCSSRuleList($1,NULL); }
	;
rule:				selectorlist LBRACE declarationlist RBRACE {$$ = createCSSRule($1, $3); }
	;
selectorlist:		selector COMMA selectorlist { $$ = createCSSSelectorList($1,$3);}
					| selector { $$ = createCSSSelectorList($1, NULL);}
	;			
selector:			STRING { $$ = createCSSSelector($1); }
	;
declarationlist: 	declaration SEMICOLON declarationlist { $$ = createCSSDeclarationList($1,$3);}
					| declaration SEMICOLON { $$ = createCSSDeclarationList($1, NULL);}
					| declaration { $$ = createCSSDeclarationList($1, NULL);}
	;				
declaration:		STRING COLON STRING { $$ = createCSSDeclaration($1, $3); }

     ;   
%%
// user code section


int main(int argc, char** argv) {
    // set inputfile
    FILE *inFile = fopen(argv[1], "r");
    if(!inFile) {
        printf("Could not open input file!\n");
        return -1;
    }
    yyin = inFile;
   
    // flex version
    //yylex();
    
    // bison: parse until there is no input anymore
    do {
        yyparse();
    } while(!feof(yyin));
    
    return 0;
}

void yyerror(const char *s) {
    printf("EEK, parse error! Message: %s\n", s);
    exit(-1);
}
