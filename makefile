run : list.o
	gcc -o run list.o
list.o : list.cpp list.h
	gcc -c list.cpp
clean :
	rm run list.o
