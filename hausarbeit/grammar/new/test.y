%{
    #include <stdio.h>
    #include <stdlib.h>
    
    extern int yylex();
    extern int yyparse();
    extern FILE *yyin;
    
    void yyerror(const char *s);
%}

// types which are found/returned by flex 
%union {
    int ival;
    float fval;
    char *sval;
}

// Terminal symbols of our language
%token <ival> INT
%token <fval> FLOAT
%token <sval> STRING

%token LBRACE RBRACE COMMA DOT SEMICOLON COLON


%%
// grammar section, parsing rules

css:				rulelist  
	;

rulelist: 			rule rulelist 
		  			| rule
	;
rule:				selectorlist LBRACE declarationlist RBRACE
	;
selectorlist:		selector COMMA selectorlist
					| selector
	;			
selector:			STRING {printf("selector: %s\n", $1); }
	;
declarationlist: 	declaration SEMICOLON declarationlist
					| declaration SEMICOLON
					| declaration
	;				
declaration:		STRING COLON STRING { printf("declaration: %s : %s\n", $1, $3); }

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
