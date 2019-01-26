#ifndef MINDSTORM_H
#define MINDSTORM_H

class Mindstorm {
public:
  int tries = 0;

  Mindstorm() {generateNo();};
  void askGuess();
  bool check();

private:
  double lsg [3], guessArray[3];

  void print3(double *);
  void print3(int *);
  void generateNo();
};

#endif
