run: main.o eigs.o matrix_util.o UI_util.o
	g++ -o run main.o eigs.o matrix_util.o UI_util.o -lgsl -lgslcblas -lm
main.o: main.cpp
	g++ -c -g main.cpp
eigs.o: eigs.cpp
	g++ -c -g eigs.cpp
matrix_util.o: matrix_util.cpp
	g++ -c -g matrix_util.cpp
UI_util.o: UI_util.cpp
	g++ -c -g UI_util.cpp
clean: 
	rm *.o
