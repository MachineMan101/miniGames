#ifndef SUDOKU_H
#define SUDOKU_H

class Sudoku {
public:
  int inserted;
  bool updated;

  Sudoku(){
    inserted = -81;
    //We will iterate over the whole sudoku and act like every entry is a number that we have found. Therefore, this number will be 0 after init and feed.
    init();
    feed();
  };
  Sudoku(int s[][9]) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        sudoku[i][j] = s[i][j];
      }
    }
    inserted = -81;
    //We will iterate over the whole sudoku and act like every entry is a number that we have found. Therefore, this number will be 0 after init and feed.
    init();
    feed();
  };
  void solve();
  void printPattern(int n);
  void printSudoku();

private:
  // int sudoku[9][9] = {
  //   {0,1,2, 6,7,9, 0,0,0},
  //   {8,0,0, 0,2,0, 0,5,0},
  //   {4,0,0, 8,0,0, 7,0,0},
  //   {9,0,7, 0,0,0, 0,0,3},
  //   {6,2,0, 0,0,0, 0,9,7},
  //   {1,0,0, 0,0,0, 2,0,5},
  //   {0,0,9, 0,0,1, 0,0,6},
  //   {0,5,0, 0,4,0, 0,0,8},
  //   {0,0,0, 9,8,3, 5,2,0}};
  int sudoku[9][9] = {
    {1,0,7, 8,0,6, 0,9,0},
    {5,0,8, 0,2,0, 0,0,3},
    {4,0,0, 0,0,0, 6,0,0},
    {0,0,0, 0,0,7, 0,0,0},
    {3,0,0, 0,0,0, 0,0,1},
    {0,0,0, 5,0,0, 0,0,0},
    {0,0,2, 0,0,0, 0,0,7},
    {8,0,0, 0,1,0, 2,0,6},
    {0,5,0, 2,0,3, 1,0,8}
  };
  bool pattern[9][10][10]; //true=verfuegbar/noch nicht gefunden

  void feed();
  void init();
  void found(int no, int zeile, int spalte);
  void eraseZeile(int no, int zeile);
  void eraseSpalte(int no, int spalte);
  void eraseSquare(int no, int zeile, int spalte);
  void erasePos(int zeile, int spalte);
  void checkZeile(int index, int zeile, int &n, int &s);
  void checkSpalte(int index, int spalte, int &n, int &z);
  void checkSquare(int index, int i, int &n, int &z, int &s);
};

#endif
