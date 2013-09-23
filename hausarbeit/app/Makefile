#include grammar/makefile.mk

all: app
	
app: lex.yy.c css.tab.c css.tab.h grammar/css_types.h
	cc grammar/css.tab.c grammar/lex.yy.c grammar/css_types.c main.c cli_parse.c css_merge.c optimizer.c output.c -o optimCSS
	
parser: lex.yy.c css.tab.c css.tab.h grammar/css_types.h
	cc grammar/css.tab.c grammar/css_types.c grammar/lex.yy.c -g -o parser

css.tab.c css.tab.h: grammar/css.y
	bison -d grammar/css.y -o grammar/css.tab.c
            
lex.yy.c: grammar/css.l css.tab.h
	flex -o grammar/lex.yy.c grammar/css.l

clean: 
	rm -f lex.yy.c grammar/css.tab.h grammar/css.tab.c grammar/parser optimCSS
