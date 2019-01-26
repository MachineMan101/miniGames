#ifndef MINDSTORMSOLVER_H
#define MINDSTORMSOLVER_H

class MindstormSolver {

private:
  bool combinations[9][9][9];

  void init();
  bool isElementOf(int , int[]);
  int matchingPositions(int, int, int);
  int shiftedPositions(int, int, int, int);
  void guessNumber();


public:
  int guess[3];
  int a, b, tries;

  MindstormSolver() { init(); }
  int countCombos();
  void dispCombos();
  bool makeGuess();
  void analysis();
};

#endif /* MY_CLASS_H */
