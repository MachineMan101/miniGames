#include <iostream>
using namespace std;

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

int main(int argc, char** argv) {
	init();
	feed();
	inserted -= 81;
	//printPattern(2);
	//so weit so gut. nun muss gecheckt werden, in welcher, zeile/spalte/quadrat nur 1 mögl. besteht für die zahl.
	int oldsolved = -1;
	while (oldsolved < inserted) {
		oldsolved = inserted;
		solve();
	}
	printSudoku();
	cout << endl << inserted << " numbers inserted.";
	//printPattern(8);
	cout << endl;
	system("pause");
	return 0;
}

void init() {
	for(int i=0; i<9; i++)
		for (int j=0; j<10; j++)
			for (int k=0; k<10; k++)
				pattern[i][j][k] = true;
}
void feed() {
	for (int i=0; i<9; i++)
		for (int j=0; j<9; j++)
			found(sudoku[i][j], i, j);
}

void found(int no, int zeile, int spalte) {
	inserted++;
	if (no==0) //leeres Kästchen. also eine Möglichkeit (1) für alle Zahlen, mach nichts
		return;
	sudoku[zeile][spalte] = no;
	eraseZeile(no-1, zeile);
	eraseSpalte(no-1, spalte);
	eraseSquare(no-1, zeile, spalte);
	erasePos(zeile, spalte);
}

void eraseZeile(int index, int zeile) {
	for (int spalte = 0; spalte <=9; spalte++)
		pattern[index][zeile][spalte] = false;
}
void eraseSpalte(int index, int spalte) {
	for (int zeile = 0; zeile <=9; zeile++)
		pattern[index][zeile][spalte] = false;
}
void eraseSquare(int index, int zeile, int spalte) {
	// int zstart = zeile/3;
	// if (zstart%3 == 0)
	// zstart -= 1;
	// int sstart = sstart/3;
	// if (sstart%3 == 0)
	// sstart -=1;
	for (int i = zeile/3*3; i < zeile/3*3+3; i++)
		for (int j = spalte/3*3; j < spalte/3*3+3; j++)
			pattern[index][i][j] = false;
}
void erasePos(int zeile, int spalte) {
	//der Platz ist für die anderen Zahlen nicht mehr verfügbar.
	for (int index = 0; index < 9; index++)
		pattern[index][zeile][spalte] = false;
}

void solve() //some repetition needed
{
	for (int index = 0; index < 9; index++) {
		for (int i = 0; i < 9; i++) {
			if (pattern[index][i][9]) {
				int n = 0, s;
				checkZeile(index, i, n, s);
				if (n == 1)
					found(index+1, i, s);
			}
			if (pattern[index][9][i]) {
				int n = 0, z;
				checkSpalte(index, i, n, z);
				if (n == 1)
					found(index+1, z, i);
			}
			//for (int i = 0; i < 9; i++) //check if there is more than one option in this square
			//{
			int n = 0, s, z;
			//cout << i%3*3 << "," << i/3*3  << endl;
			checkSquare(index, i, n, s, z);
			if (n == 1)
				found(index+1, z, s);
			//}
		}
	}
}
void checkSquare(int index, int i, int &n, int &s, int &z) //currently non-sensed or isn't it?
{
	//cout << "\nSpalte" << i%3*3 << " Zeile" << i/3*3;
	int zeilenAnfang = i/3*3, spaltenAnfang = i%3*3;
	for (int zeile = zeilenAnfang; zeile < zeilenAnfang+3; zeile++)
		for (int spalte = spaltenAnfang; spalte < spaltenAnfang+3; spalte++)
			if (pattern[index][zeile][spalte]) {
				n++;
				s = spalte; z = zeile;
			}
}
void checkZeile(int index, int zeile, int &n, int &s) {
	for (int spalte = 0; spalte < 9; spalte++)
		if (pattern[index][zeile][spalte]) {
			n++;
			s = spalte;
		}
}
void checkSpalte(int index, int spalte, int &n, int &z) {
	for (int zeile = 0; zeile < 9; zeile++)
		if (pattern[index][zeile][spalte]) {
		n++;
		z = zeile;
	}
}

void printPattern(int n) {
	cout << endl << "_____________________________________";
	for(int i = 0; i < 10; i++) {
		cout << endl << "| ";
		for (int j = 0; j < 10; j++)
			cout << pattern[n][i][j] << " | ";
		cout << endl << "_____________________________________";
	}
}
void printSudoku() {
	cout << endl << "_____________________________________";
	for(int i = 0; i < 9; i++) {
		cout << endl << "| ";
		for (int j = 0; j < 9; j++)
			cout << sudoku[i][j] << " | ";
	cout << endl << "_____________________________________";
	}
}
