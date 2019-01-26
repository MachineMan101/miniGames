#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "Mindstorm.h"
using namespace std;


// int main(int argc, char** argv) {
// 	cout << "Welcome to Mindstorm!" << endl;
// 	cout << "---------------------" << endl;
// 	cout << "A random number between 0 and 999 has been generated. The number does not contain the same letter more than once."
// 	<< "You need to guess the number correctly.\n"
// 	<< "For every letter guessed correctly, a is increased by the value 1 if the letter has the correct position. If the letter "
// 	<< "does not have the correct position, b is increased by 1. I.e. if a = b = 0, no letter was correct.\n";
//
// 	Mindstorm m;
// 	// m.generateNo();
// 	//print3(&lsg[0]);
// 	m.askGuess();
// 	//cout << endl << "guess Array";
// 	//print3(&guessArray[0]);
// 	while (!m.check()) {
// 		m.askGuess();
// 		//print3(&guessArr[0]);
// 	}
// 	cout << endl << "You have won the game!!";
// 	cout << endl << m.tries << " attempts used.\n\n";
// 	return 0;
// }

void Mindstorm::generateNo() {
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

void Mindstorm::askGuess() {
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

bool Mindstorm::check() {
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
	cout << "\na = " << a << ", b = " << b << endl;
	if (a == 3)
		rv = true;
	return rv;
}

void Mindstorm::print3(double *a) {
	cout << endl;
	for (int i = 0; i < 3; i++)
		cout << a[i];
}
