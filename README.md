# miniGames
This a collection of some (small) private projects in C++. 
Compile all Projects with
```shell
$make
````
compile only SudokuSolver with
```shell
$make Sudoku
````
and compile only mindstorm-game with
```shell
$make MindstormMaster
````
clean up with:
```shell
$make clean
````

## MindstormMaster
Executes Mindstorm and MindstormSolver which should now longer be executed on their own. Lets you choose which gamemode you want to play. Instructions on how to play are displayed when executing the code. See below for a (very) brief description of the game.
_NOTE: This has only been tested in Linux Ubuntu. It is unknown whether the competitive mode works in the Windows shell as well (Colors)._

### Mindstorm
Lets you play mindstorm. A game where you have to correctly guess a number with three figures. The Computer gives you hints on how many numbers in your last guess were correct and or at the correct place.

### MindstormSolver
Reverses the roles from Mindstorm. You think of a number, and the computer has to find it out while you give it some hints.

## Sudoku
Solves Sudokus. The Sudoku has to be hard-coded, though. A Java GUI will be uploaded at some point. Using Computer Vision would be cooler...
