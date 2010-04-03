run : list.o
	g++ -o run list.o
list.o : list.cpp list.h
	g++ -c list.cpp
clean :
	rm run list.o
