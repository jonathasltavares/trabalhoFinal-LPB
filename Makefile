all:	programa.e
programa.e:	main.o	pgm.o	lbp.o
	gcc	-o	programa.e	main.o	pgm.o	lbp.o -lm
main.o:	main.c
	gcc	-o	main.o	-c	main.c
pgm.o:	pgm.c
	gcc	-o	pgm.o	-c	pgm.c
lbp.o:	lbp.c
	gcc	-o	lbp.o	-c	lbp.c
run:
	./programa.e
clean:
	rm	-rf	*.o