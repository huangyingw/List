run : list.o
<<<<<<< HEAD:makefile
	g++ -o run list.o
list.o : list.cpp list.h
	g++ -c list.cpp
=======
	gcc -o run list.o
list.o : list.cpp list.h
	gcc -c list.cpp
>>>>>>> master:makefile
clean :
	rm run list.o
