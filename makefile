run: main.o eigs.o
	g++ -o run main.o eigs.o -lgsl -lgslcblas -lm
main.o: main.cpp
	g++ -c main.cpp
eigs.o: eigs.cpp
	g++ -c eigs.cpp
clean: 
	rm *.o
