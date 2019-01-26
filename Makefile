all: MindstormMaster Sudoku

MindstormMaster: MindstormMaster.cpp MindstormSolver.cpp Mindstorm.cpp
	g++ MindstormMaster.cpp -o MindstormMaster

# MindstormSolver: MindstormSolver.cpp
# 	g++ MindstormSolver.cpp -o MindstormSolver
#
# Mindstorm: Mindstorm.cpp
# 	g++ Mindstorm.cpp -o Mindstorm

Sudoku: Sudoku.cpp
	g++ Sudoku.cpp -o Sudoku

clean:
	rm -rf *.o
	rm MindstormMaster Mindstorm MindstormSolver Sudoku
