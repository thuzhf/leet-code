all: a.out

a.out: main.o 
	g++ main.o

main.o: main.cpp add-two-numbers.hpp
	g++ -c main.cpp

clean:
	rm *.o *.out
