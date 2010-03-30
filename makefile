run : jpg.o
	gcc -o run jpg.o
jpg.o : jpg.c regulator.c fprintf.c
	gcc -c jpg.c
clean :
	rm run jpg.o
