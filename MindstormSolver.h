#ifndef MINDSTORMSOLVER_H
#define MINDSTORMSOLVER_H

bool firstArg[9], secondArg[9][9], thirdArg[9][9][9];
//firstArg and secondArg are here because I pictured this algorithm as a tree. They can be avoided. The search is a bit less efficient then but the code gets less complex.
int guess[3];
int a, b, tries;

void init();
void guessNumber();
void eliminatePaths();
void analysis();
bool isElementOf(int , int[]);
int matchingPositions(int, int, int);
int shiftedPositions(int, int, int, int);

#endif /* MY_CLASS_H */
