CPP11 = -std=c++11
PYTHON = -I/usr/include/python2.7 -lpython2.7

run: main.o eigs.o matrix_util.o UI_util.o
	g++ -o run main.o eigs.o matrix_util.o UI_util.o -lgsl -lgslcblas -lm $(CPP11) $(PYTHON)
main.o: main.cpp
	g++ -c $(CPP11) $(PYTHON) -g main.cpp
eigs.o: eigs.cpp
	g++ -c $(CPP11) $(PYTHON) -g eigs.cpp
matrix_util.o: matrix_util.cpp
	g++ -c $(CPP11) $(PYTHON) -g matrix_util.cpp
UI_util.o: UI_util.cpp
	g++ -c $(CPP11) $(PYTHON) -g UI_util.cpp
clean:
	rm *.o run
