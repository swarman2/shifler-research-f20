run: main.o eigs.o
	g++ -o run main.o eigs.o -lgsl -lgslcblas -lm
main.o: main.cpp
	g++ -c -g main.cpp
eigs.o: eigs.cpp
	g++ -c -g eigs.cpp
clean: 
	rm *.o
