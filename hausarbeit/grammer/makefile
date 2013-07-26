a.out: y.tab.o lex.yy.o
	gcc -o css_2_1 -g y.tab.o lex.yy.o

y.tab.o: y.tab.c
	cc -g -c y.tab.c

y.tab.c: css_2_1.grm
	bison -o y.tab.c -dv -r itemset css_2_1.grm

y.tab.h: y.tab.c
	echo "y.tab.h was created at the same time as y.tab.c"

lex.yy.o: lex.yy.c y.tab.h
	cc -g -c lex.yy.c

lex.yy.c: css_2_1.lex
	flex css_2_1.lex

clean: 
	rm -f lex.yy.c a.out y.tab.c y.tab.h y.tab.o lex.yy.o 
