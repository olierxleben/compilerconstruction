a.out: parse.o y.tab.o lex.yy.o errormsg.o util.o absyn.o symbol.o prabsyn.o table.o semant.o translate.o types.o env.o
	gcc -o parser -g absyn.o parse.o y.tab.o lex.yy.o semant.o errormsg.o util.o symbol.o prabsyn.o table.o  translate.o types.o env.o

parse.o: parse.c errormsg.h util.h
	cc -g -c parse.c
	
absyn.o: absyn.c errormsg.h util.h absyn.h
	cc -g -c absyn.c
	
symbol.o: symbol.c errormsg.h util.h
	cc -g -c symbol.c

semant.o: semant.c semant.h errormsg.h util.h absyn.h symbol.h types.h
	cc -g -c semant.c
	
translate.o: translate.c translate.h util.h errormsg.h symbol.h absyn.h
	cc -g -c translate.c
	
table.o: table.c table.h
	cc -g -c table.c
	
env.o: env.c env.h
	cc -g -c env.c
	
types.o: types.c types.h
	cc -g -c types.c
	
prabsyn.o: prabsyn.c prabsyn.h
	cc -g -c prabsyn.c

y.tab.o: y.tab.c
	cc -g -c y.tab.c

y.tab.c: tiger.grm
	bison -o y.tab.c -dv -r itemset tiger.grm

y.tab.h: y.tab.c
	echo "y.tab.h was created at the same time as y.tab.c"

errormsg.o: errormsg.c errormsg.h util.h
	cc -g -c errormsg.c

lex.yy.o: lex.yy.c y.tab.h errormsg.h util.h
	cc -g -c lex.yy.c

lex.yy.c: tiger.lex
	flex tiger.lex

util.o: util.c util.h
	cc -g -c util.c

clean: 
	rm -f lex.yy.c a.out symbol.o table.o prabsyn.o  absyn.o util.o parse.o errormsg.o y.tab.c y.tab.h y.tab.o  lex.yy.o semant.o env.o parser.exe y.output 
