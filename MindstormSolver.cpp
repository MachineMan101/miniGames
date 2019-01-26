#include <iostream>
#include "MindstormSolver.h"
using namespace std;


int main(int argc, char** argv) {
	cout << "Please think of a number with three letters. It may not contain the same letter twice.\n";
	cout << "Example: 123 is ok, but 122 is not because it contains the letter 2 twice.\n\n";
	init();

	while(true) {
		tries++;
		// cout << countCombos() << " Combinations left.\n";
		guessNumber();
		cout << "Is the number " << guess[0] << guess[1] << guess[2] << "?\n";
		cout << "Enter Number of correct letters at the correct place: ";
		cin >> a;
		if (a == 3) {
			cout << endl << "I won!!! This was easy.";
			break;
		}
		cout << "Enter Number of correct letters at incorrect places: ";
		cin >> b;
		analysis();
	}
	cout << endl << endl << tries << " Guesses used." << endl << endl;
}

void dispCombos() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			for (int k = 0; k < 9; k++) {
				if(combinations[i][j][k])
				cout << i+1 << j+1 << k+1 << endl;
			}
		}
	}
}

int countCombos() {
	int count = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			for (int k = 0; k < 9; k++) {
				if (combinations[i][j][k])
				count++;
			}
		}
	}
	if (count <= 5) {
		dispCombos();
	}
	return count;
}

void analysis() {
	int correctLetters = a + b;
	//eliminate all combinations that do not contain the correct number of correct letters ;-P
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			for (int k = 0; k < 9; k++) {
				if (isElementOf(i+1, guess) + isElementOf(j+1, guess) + isElementOf(k+1, guess) != correctLetters) {
					combinations[i][j][k] = false;
				} else {
					//we have the correct number of letters. now we have to make sure, the positions are possible as well.
					if (!(matchingPositions(i,j,k) == a && shiftedPositions(i,j,k,correctLetters) == b))
						combinations[i][j][k] = false;
				}
			}
		}
	}
}

int matchingPositions(int one, int two, int three){
	return (one+1 == guess[0]) + (two+1 == guess[1]) + (three+1 == guess[2]);
}

int shiftedPositions(int one, int two, int three, int correctLetters) {
	return correctLetters - matchingPositions(one, two, three);
}

bool isElementOf(int candidate, int liste[]) {
	int length = 3;//sizeof(liste)/sizeof(*liste);
	for (int i = 0; i < length; i++) {
		if (liste[i] == candidate)
			return true;
	}
	return false;
}

void guessNumber() {
	// choose first true values.
	int a = 0, b = 0, c = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			for (int k = 0; k < 9; k++) {
				if (combinations[i][j][k]) {
					a = i; b = j; c = k;
					break;
				}
			}
			if (combinations[a][b][c])
			break;
		}
		if (combinations[a][b][c])
		break;
	}
	guess[0] = a+1;
	guess[1] = b+1;
	guess[2] = c+1;
}

void init() {
	tries = 0;
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++) {
			if (i != j) {
				for (int k = 0; k < 9; k++) {
					if (j != k && i != k) {
						combinations[i][j][k] = true;
					}
				}
			}
		}
	}
}
