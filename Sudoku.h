#ifndef SUDOKU_H
#define SUDOKU_H

int sudoku[9][9] = {
{0,1,2, 6,7,9, 0,0,0},
{8,0,0, 0,2,0, 0,5,0},
{4,0,0, 8,0,0, 7,0,0},
{9,0,7, 0,0,0, 0,0,3},
{6,2,0, 0,0,0, 0,9,7},
{1,0,0, 0,0,0, 2,0,5},
{0,0,9, 0,0,1, 0,0,6},
{0,5,0, 0,4,0, 0,0,8},
{0,0,0, 9,8,3, 5,2,0}};
bool pattern[9][10][10]; //true=verfuegbar/noch nicht gefunden
int inserted = 0;

void feed();
void init();
void found(int no, int zeile, int spalte);
void printPattern(int n);
void printSudoku();
void eraseZeile(int no, int zeile);
void eraseSpalte(int no, int spalte);
void eraseSquare(int no, int zeile, int spalte);
void erasePos(int zeile, int spalte);
void solve();
void checkZeile(int index, int zeile, int &n, int &s);
void checkSpalte(int index, int spalte, int &n, int &z);
void checkSquare(int index, int i, int &n, int &z, int &s);

#endif
