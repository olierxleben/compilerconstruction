#include grammar/makefile.mk

all: app
	
app: lex.yy.c test.tab.c test.tab.h grammar/css_types.h
	cc grammar/test.tab.c grammar/lex.yy.c grammar/css_types.c main.c cli_parse.c css_merge.c guiCSS.c optimizer.c  -lncurses -o optimCSS
	
parser: lex.yy.c test.tab.c test.tab.h grammar/css_types.h
	cc grammar/test.tab.c grammar/css_types.c grammar/lex.yy.c -o parser

test.tab.c test.tab.h: grammar/test.y
	bison -d grammar/test.y -o grammar/test.tab.c
            
lex.yy.c: grammar/test.l test.tab.h
	flex -o grammar/lex.yy.c grammar/test.l

clean: 
	rm -f lex.yy.c grammar/test.tab.h grammar/test.tab.c grammar/parser optimCSS
