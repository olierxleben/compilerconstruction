a.out: main.o prog1.o prog2.o table.o slp.o util.o
	gcc -g main.o prog1.o prog2.o table.o slp.o util.o

main.o: main.c slp.h util.h
	gcc -g -c main.c

prog1.o: prog1.c slp.h util.h
	gcc -g -c prog1.c
	
prog2.o: prog2.c slp.h util.h
	gcc -g -c prog2.c

table.o: table.c util.h 
	gcc -g -c table.c

slp.o: slp.c slp.h util.h
	gcc -g -c slp.c

util.o: util.c util.h
	gcc -g -c util.c

clean: 
	rm -f a.out util.o prog1.o prog2.o table.o slp.o main.o
