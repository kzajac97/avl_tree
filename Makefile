CXXFLAGS = -Wall -pedantic -std=c++0x

__START__:avl
	./avl

avl: main.o avl.o
	g++ -o avl main.o avl.o

main.o: main.cpp
	g++ -c ${CXXFLAGS} main.cpp

clean:
	rm -f *.o avl