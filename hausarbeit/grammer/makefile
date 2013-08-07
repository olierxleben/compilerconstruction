a.out: css_types.o y.tab.o lex.yy.o
	gcc -o css_2_1 -g y.tab.o lex.yy.o

css_types.o: css_types.c
	cc -g -c css_types.c

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
	rm -f css_types.o lex.yy.c a.out y.tab.c y.tab.h y.tab.o y.output lex.yy.o css_types.o css_2_1
