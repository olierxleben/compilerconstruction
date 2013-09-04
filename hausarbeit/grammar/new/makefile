# all: parser
# 
# parser: lex.yy.c css.tab.c css.tab.h
# 	gcc css.tab.c lex.yy.c -lfl -o parser
# 
# css.tab.c css.tab.h: css.grm
# 	bison -d css.grm
#             
# lex.yy.c: css.lex css.tab.h
# 	flex css.lex
# 
# clean: 
# 	rm -f lex.yy.c css.tab.h css.tab.c a.out

a.out: css_types.o y.tab.o lex.yy.o
	cc -o css_2_1 -g css_types.o y.tab.o lex.yy.o

css_types.o: css_types.c
	cc -g -c css_types.c

y.tab.o: y.tab.c
	cc -g -c y.tab.c

y.tab.c: css.grm
	bison -o y.tab.c --debug -dv -r itemset css.grm

y.tab.h: y.tab.c
	echo "y.tab.h was created at the same time as y.tab.c"

lex.yy.o: lex.yy.c y.tab.h
	cc -g -c lex.yy.c

lex.yy.c: css.lex
	flex css.lex

clean: 
	rm -f lex.yy.c a.out y.tab.c y.tab.h y.tab.o y.output lex.yy.o css_types.o css_2_1