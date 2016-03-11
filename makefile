rational:	rational.o main.o
	g++ rational.o main.o -o rational
main.o: main.cpp rational.h
	g++ -c main.cpp
rational.o: rational.cpp rational.h
	g++ -c rational.cpp
