#include <iostream>
// #include <time.h>
#include "Mindstorm.cpp"
#include "MindstormSolver.cpp"

using namespace std;

int main(int argc, char** argv) {
  cout << "Welcome to Mindstorm, a game where you have to guess a number with\n"
  << "three letters correctly.\n\n";
  char c;

  while(true) {
    cout << "Please enter a gamemode.\ni for instructions\nt for training\nb for computer\nc for competitive\ne for exit\n\n";
    cin >> c;
    cout << endl;

    if (c == 'i') {
      cout << endl << endl;
      cout << "Welcome to Mindstorm!" << endl;
      cout << "---------------------" << endl;
      cout << "You or the computer will think of a random number between 0 and 999. The number must not contain the same letter more than once."
      << "The other one of the two of you will need to guess the number correctly.\n"
      << "For every letter guessed correctly, a is increased by the value 1 if the letter has the correct position. If the letter "
      << "does not have the correct position, b is increased by 1. I.e. if a = b = 0, no letter was correct.\n"
      << "If the solution is 123 and the guess is 134, a and b would both be 1, since 1 is a correct letter and at the correct position and 3 "
      << "is a correct letter but at the wrong position.\n";
      cout << endl << endl;
    } else if (c == 't') {
      Mindstorm m;
      cout << "The computer has generated a number. You need to guess.\n";
      m.askGuess();
      while (!m.check()) {
        m.askGuess();
      }
      cout << endl << "You have won the game!!";
      cout << endl << m.tries << " attempts used.\n\n";
      return 0;
    } else if (c == 'b') {
      cout << "Please think of a number with three letters. The computer will try to guess it.\n";
      MindstormSolver ms;
    	while(!ms.makeGuess());
    	cout << endl << endl << ms.tries << " attempts used." << endl << endl;
      return 0;
    } else if (c == 'c') {
      //TODO
      cout << "You and the computer will both think of a number each. Let's see who can guess the other one's number first.\n";
      MindstormSolver ms;
      Mindstorm m;

      while (true) {
        cout << "\033[34m";
        m.askGuess();
        if (m.check()) {
          cout << "You have won! Congratulations for besting the computer!\n";
          // clock_t t = clock();
          // while(((float)(clock() - t))/CLOCKS_PER_SEC < 1.);
          cout << "\033[1;31mPlease enter the name of your Mother below:\n";
          char name[100];
          // cin.getline(name,sizeof(name));    does not wait for input????
          cin >> name;
          cout << "Initializing terminator program...\n";
          cout << "Target: Sarah Connor deleted....\n";
          cout << "Target: " << name << " added....\n";
          cout << "\033[0m";
          cout << endl << m.tries << " attempts used.\n\n";
          return 0;
        }
        cout << "\n\n\033[31m";
        if (ms.makeGuess()) {
          cout << "\033[1mI have won! Kneel before the machine, tiny human!\n";
          cout << "Not even Arnold can save you now!\n";
          cout << "\033[0m";
          cout << endl << ms.tries << " attempts used.\n\n";
          return 0;
        }
        cout << "\033[0m";
      }

      return 0;
    } else if (c == 'e') {
      return 0;
    } else {
      cout << "Unknown input. Please enter one of the characters above.\n\n";
    }
  }
}
