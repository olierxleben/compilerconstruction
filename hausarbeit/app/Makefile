all: app parser
	
app: 
	cc main.c cli_parse.c css_merge.c -lncurses -o optimCSS
	
parser: lex.yy.c test.tab.c test.tab.h css_types.h
	cc test.tab.c css_types.c printCSS.c lex.yy.c -o parser

test.tab.c test.tab.h: test.y
	bison -d test.y
            
lex.yy.c: test.l test.tab.h
	flex test.l

clean: 
	rm -f lex.yy.c test.tab.h test.tab.c parser