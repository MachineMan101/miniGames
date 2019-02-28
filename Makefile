all: MindstormMaster Sudoku

MindstormMaster: MindstormMaster.cpp MindstormSolver.cpp Mindstorm.cpp MindstormMaster.h MindstormSolver.h Mindstorm.h
	g++ MindstormMaster.cpp -o MindstormMaster

# MindstormSolver: MindstormSolver.cpp
# 	g++ MindstormSolver.cpp -o MindstormSolver
#
# Mindstorm: Mindstorm.cpp
# 	g++ Mindstorm.cpp -o Mindstorm

Sudoku: Sudoku.cpp Sudoku.h
	g++ Sudoku.cpp -o Sudoku

clean:
	rm -rf *.o
	rm MindstormMaster Mindstorm MindstormSolver Sudoku
