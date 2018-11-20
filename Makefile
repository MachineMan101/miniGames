all: MindstormSolver Mindstorm Sudoku

MindstormSolver: MindstormSolver.cpp
	g++ MindstormSolver.cpp -o MindstormSolver

Mindstorm: Mindstorm.cpp
	g++ Mindstorm.cpp -o Mindstorm

Sudoku: Sudoku.cpp
	g++ Sudoku.cpp -o Sudoku

clean:
	rm -rf *.o
	rm Mindstorm MindstormSolver Sudoku
