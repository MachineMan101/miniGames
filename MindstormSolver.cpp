#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

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

int main(int argc, char** argv) {
	cout << "Please think of a number with three letters. It may not contain the same letter twice.\n";
	cout << "Example: 123 is ok, but 122 is not because it contains the letter 2 twice.\n\n";
	init();
	
	while(true) {
		tries++;
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
	system("pause");
}

void analysis() {
	int correctLetters = a + b;
	/**if (correctLetters == 0) {
		//eliminate all combinations with these letters
		for (int i = 0; i < 3; i++) {
			firstArg[guess[i]-1] = false;
			for (int j = 0; j < 9; j++) {
				secondArg[guess[i]-1][j] = false;
				secondArg[j][guess[i]-1] = false;
				for (int k = 0; k < 9; k++) {
					thirdArg[guess[i]-1][j][k] = false;
					thirdArg[j][guess[i]-1][k] = false;
					thirdArg[j][k][guess[i]-1] = false;
				}
			}
		}
		return false;
	}*/
	//it is starting to suck to code this.
	//eliminate all combinations that do not contain the correct number of correct letters ;-P
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			for (int k = 0; k < 9; k++) {
				if (isElementOf(i+1, guess) + isElementOf(j+1, guess) + isElementOf(k+1, guess) != correctLetters) {
					thirdArg[i][j][k] = false;
					// just delete this combination. Maybe include a loop that deletes secondArgs (if all thirdArgs == false) as well later.
				} else {
					//we have the correct number of letters. now we have to make sure, the positions are possible as well.
					if (!(matchingPositions(i,j,k) == a && shiftedPositions(i,j,k,correctLetters) == b))
						thirdArg[i][j][k] = false;
				}
			}
		}
	}
	
	eliminatePaths();
}

int matchingPositions(int one, int two, int three){
	return (one+1 == guess[0]) + (two+1 == guess[1]) + (three+1 == guess[2]);
}

int shiftedPositions(int one, int two, int three, int correctLetters) {
	return correctLetters - matchingPositions(one, two, three);
}

void eliminatePaths() {
	for (int i = 0; i < 9; i++) {
		bool secondTier = false;
		for (int j = 0; j < 9; j++) {
			bool thirdTier = false;
			for (int k = 0; k < 9; k++) {
				if (thirdArg[i][j][k])
					thirdTier = true;
			}
			secondArg[i][j] = thirdTier;
			if (secondArg[i][j])
				secondTier = true;
		}
		firstArg[i] = secondTier;
	}
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
	int i, j, k;
	for (i = 0; i < 9; i++) {
		if (firstArg[i]) {
			for (j = 0; j < 9; j++) {
				if (secondArg[i][j]) {
					for (k = 0; k < 9; k++) {
						if (thirdArg[i][j][k])
							break;
					}
					if (thirdArg[i][j][k])
						break;
				}
			}
			if (secondArg[i][j] && thirdArg[i][j][k]) 
				break;
		}
	}
	guess[0] = i+1; guess[1] = j+1; guess[2] = k+1;
}

void init() {
	tries = 0;
	for (int i = 0; i < 9; i++){
		firstArg[i] = true;
		for (int j = 0; j < 9; j++) {
			if (i != j) {
				secondArg[i][j] = true;
				for (int k = 0; k < 9; k++) {
					if (j != k && i != k) {
						thirdArg[i][j][k] = true;
					}
				}
			}
		}
	}
}
