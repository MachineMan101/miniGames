#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

double lsg [3], guessArray[3];
int tries = 0;

void print3(double *);
void print3(int *);
void generateNo();
void askGuess();
bool check();

int main(int argc, char** argv) {
	cout << "Welcome to Mindstorm!" << endl;
	cout << "---------------------" << endl;
	cout << "A random number between 0 and 999 has been generated. The number does not contain the same letter more than once." 
	<< "You need to guess the number correctly.\n"
	<< "For every letter guessed correctly, a is increased by the value 1 if the letter has the correct position. If the letter "
	<< "does not have the correct position, b is increased by 1. I.e. if a = b = 0, no letter was correct.\n";
	generateNo();
	//print3(&lsg[0]);
	askGuess();
	//cout << endl << "guess Array";
	//print3(&guessArray[0]);
	while (!check()) {
		askGuess();
		//print3(&guessArr[0]);
	}
	cout << endl << "You have won the game!!";
	cout << endl << tries << " attempts used.\n\n";
	system("pause");
	return 0;
}

void generateNo() {
	srand(time(NULL));
	for(int i=0; i<3; i++) {
		lsg[i] = rand()%9+1;
		for (int j=0; j<i; j++) {
			if (lsg[j] == lsg[i]) {
				//cout << endl << i+1 << lsg[i];
				i--;
			}
		}
	}
}

void askGuess() {
	double guess;
	cout << endl << "Enter your guess: ";
	cin >> guess;
	if (guess < 100 || guess > 999) {
		cout << "Invalid Number entered, try again.";
		return;
	}
	for (int i = 2; i >= 0; i--) {
		guess /= 10;
		double fpart, ipart;
		fpart = round(modf(guess, &ipart) *10);
		//cout << endl << i << "th part of the number: " << fpart << ", " << ipart;
		guess = ipart;
		//cout << endl << fpart;
		guessArray[i] = fpart;
	}
	tries++;
}

bool check() {
	bool rv = false;
	int a = 0, b=0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			//cout << endl << i << ", " << j << "\t" << guessArray[i] << " ?= " << lsg[j] << "\t" << ((int)guessArray[i]==(int)lsg[j]);
			if (guessArray[i] == lsg[j]) {
				if (i == j) {
					a++;
				}
				else {
					b++;
				}
			}
		}
	}
	cout << "\na=" << a << ", b=" << b;
	if (a == 3)
		rv = true;
	return rv;
}

void print3(double *a) {
	cout << endl;
	for (int i = 0; i < 3; i++)
		cout << a[i];
}
