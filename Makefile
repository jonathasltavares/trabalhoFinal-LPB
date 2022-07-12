all:	programa.exe
programa.exe:	main.o	pgm.o	lbp.o
	gcc	-o	programa.exe	main.o	pgm.o	lbp.o
main.o:	main.c
	gcc	-o	main.o	-c	main.c
pgm.o:	pgm.c
	gcc	-o	pgm.o	-c	pgm.c
lbp.o:	lbp.c
	gcc	-o	lbp.o	-c	lbp.c
run:
	./programa.exe
clean:
	rm	-rf	*.o