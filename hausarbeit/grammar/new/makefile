all: parser

parser: lex.yy.c test.tab.c test.tab.h
	gcc test.tab.c lex.yy.c -lfl -o parser

test.tab.c test.tab.h: test.y
	bison -d test.y
            
lex.yy.c: test.l test.tab.h
	flex test.l

clean: 
	rm -f lex.yy.c test.tab.h test.tab.c a.out
