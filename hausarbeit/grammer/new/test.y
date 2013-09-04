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

%%
// grammar section, parsing rules

css:
        INT css         { printf("bison found an int: %d\n", $1); }
        | FLOAT css     { printf("bison found a float: %f\n", $1); }
        | STRING css    { printf("bison found a string: %s\n", $1); }
        | INT               { printf("bison found an int: %d\n", $1); }
        | FLOAT             { printf("bison found a float: %f\n", $1); }
        | STRING            { printf("bison found a string: %s\n", $1); }
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
