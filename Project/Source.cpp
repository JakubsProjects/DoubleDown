
/*TA Notes:
1. when user enters invalid piece or location, should let user know which case it is and then prompt user for input again  -1

Total Grade: 99/100

*/


#include <iostream>
using namespace std;

//Defining TRUE and FALSE values
#define TRUE 1
#define FALSE 0
int W = 0;
//Project 4 is called DoubleDown. DoubleDown is a game for two players. One will piece a piece and the other will choice a place or location.
//If one of the players get four upper case characters, four lower-case characters, four vowels (a,e,i,o) or four consonants they win.

//Printing Information about the game
void PrintInfo() {

	cout << "Authors: Eric and Jakub\n";
	cout << "Programming Assignment 4: DoubleDown\n";
	cout << "Date: 10/27/2016\n\n";
}

//Printing the instructions
void PrintGameAndInstructions() {
	cout << "Welcome to the game of DoubleDown, where you try to complete a set of four pieces that are alike.  Players take turns making moves. On each move your OPPONENT chooses the piece, then YOU get to place it on the board.  If you create a set of four alike when you place your piece, then you win! A set of four alike can be completed by using four upper case characters, four lower-case characters, four vowels (a,e,i,o) or four consonants\n\n";

	cout << "The game level determines which positions can be used in completing four alike pieces.  Level one checks for four alike in every row, column, and diagonal.  Level two additionally checks for the pieces in the four corners as well as each cluster of four in each corner.\n\n";



}

//Printing Basic gameboard
void printGameBoard() {
	cout << "When prompted for piece to use you may also: Enter 's' to change program level. Enter 'x' to exit the program.\n\n";

	cout << "|---------|  Square #\n"
		<< "| . . . . |  1  2  3  4\n"
		<< "| . . . . |  5  6  7  8\n"
		<< "| . . . . |  9  10 11 12\n"
		<< "| . . . . |  13 14 15 16\n"
		<< "|---------|             \n"
		<< "Pieces: AEIO aeio BCDF bcdf\n"
		<< endl;

}

//Function that will print out update gameboard with the available positiongs and pieces
void ChangesBoard(int NumberArray[4][4], char gameBoardArray[16], char gameBoardPieces[16]) {
	cout << "|---------|  Square #\n";
	cout << "|" << " " << gameBoardArray[0] << " " << gameBoardArray[1] << " " << gameBoardArray[2] << " " << gameBoardArray[3] << " " << "|" << "  1  2  3  4\n";

	cout << "|" << " " << gameBoardArray[4] << " " << gameBoardArray[5] << " " << gameBoardArray[6] << " " << gameBoardArray[7] << " " << "|" << "  5  6  7  8\n";

	cout << "|" << " " << gameBoardArray[8] << " " << gameBoardArray[9] << " " << gameBoardArray[10] << " " << gameBoardArray[11] << " " << "|" << "  9  10 11 12\n";

	cout << "|" << " " << gameBoardArray[12] << " " << gameBoardArray[13] << " " << gameBoardArray[14] << " " << gameBoardArray[15] << " " << "|" << "  13 14 15 16\n";

	cout << "|---------|             \n";



}

//Function to check user input, this includes their number and letters. Returning FALSE if the number or letter are invalid. Returning TRUE is the number and letter are valid
int UserInput(char &letter, int &number, int NumberArray[4][4], char gameBoardArray[16], char gameBoardPieces[16]) {


	//Check if their number is valid
	if (number == 1 || number == 2 || number == 3 || number == 4 || number == 5 || number == 6 || number == 7 || number == 8 || number == 9 || number == 10 || number == 11 || number == 12 || number == 13 || number == 14 || number == 15 || number == 16) {

		//Check if their letter is valid
		if (letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'B' || letter == 'C' || letter == 'D' || letter == 'F' || letter == 'b' || letter == 'c' || letter == 'd' || letter == 'f') {

			//Checking if their letter doesnt already equal a letter on the gameboard
			for (int i = 0; i < 16; i++) {

				if (letter == gameBoardArray[i]) {
					return FALSE;
				}
			}

			//Checking if their number is not already being used on the gameboard
			if (gameBoardArray[number - 1] != '.') {
				return FALSE;
			}
			//If valid number and letter are choosen then set the gameboard to that position and piece.
			number = number - 1;
			gameBoardArray[number] = letter;

		}
	}
	return TRUE;
}


//Creating function that change the pieces on the gameboard if their are already being used
void gameBoardPiecesChange(char &letter, int &number, char gameBoardArray[16], char gameBoardPieces[16]) {
	cout << "Pieces: ";

	//Looping through all the letters on the gameboard, if the letter equals to something on the gameboard then it will replace it with a space
	for (int i = 0; i < 16; i++) {
		if (letter == gameBoardPieces[i]) {
			gameBoardPieces[i] = ' ';
		}

		cout << gameBoardPieces[i] << " ";
	}
	cout << "\n";
}

//Creating function that will check for winnnigs if the LEVEL is 2. This will check TOP CORNERS. Returns TRUE if a winning is found in those sections and returns FALSE if no winning is found
int Level2TopCorners(char gameBoardArray[]) {
	for (int k = 0; k <= 3; k = k + 2) {
		for (int i = 0; i < 1; i++) {

			//Declares win for TOP corners for upper case and lower case CONSONANTS
			if (((gameBoardArray[i + k] == 'F') || (gameBoardArray[i + k] == 'B') || (gameBoardArray[i + k] == 'C') || (gameBoardArray[i + k] == 'D') || (gameBoardArray[i + k] == 'b') || (gameBoardArray[i + k] == 'c') || (gameBoardArray[i + k] == 'd') || (gameBoardArray[i + k] == 'f'))
				&& ((gameBoardArray[i + 1 + k] == 'B') || (gameBoardArray[i + 1 + k] == 'C') || (gameBoardArray[i + 1 + k] == 'D') || (gameBoardArray[i + 1 + k] == 'F') || (gameBoardArray[i + 1 + k] == 'b') || (gameBoardArray[i + 1 + k] == 'c') || (gameBoardArray[i + 1 + k] == 'd') || (gameBoardArray[i + 1 + k] == 'f'))
				&& ((gameBoardArray[i + 4 + k] == 'B') || (gameBoardArray[i + 4 + k] == 'C') || (gameBoardArray[i + 4 + k] == 'D') || (gameBoardArray[i + 4 + k] == 'F') || (gameBoardArray[i + 4 + k] == 'b') || (gameBoardArray[i + 4 + k] == 'c') || (gameBoardArray[i + 4 + k] == 'd') || (gameBoardArray[i + 4 + k] == 'f'))
				&& ((gameBoardArray[i + 5 + k] == 'B') || (gameBoardArray[i + 5 + k] == 'C') || (gameBoardArray[i + 5 + k] == 'D') || (gameBoardArray[i + 5 + k] == 'F') || (gameBoardArray[i + 5 + k] == 'b') || (gameBoardArray[i + 5 + k] == 'c') || (gameBoardArray[i + 5 + k] == 'd') || (gameBoardArray[i + 5 + k] == 'f'))) {
				return TRUE;
			}

			//Declares win for TOP corners for upper case and lower case VOWELS
			if (((gameBoardArray[i + k] == 'A') || (gameBoardArray[i + k] == 'E') || (gameBoardArray[i + k] == 'I') || (gameBoardArray[i + k] == 'O') || (gameBoardArray[i + k] == 'a') || (gameBoardArray[i + k] == 'e') || (gameBoardArray[i + k] == 'i') || (gameBoardArray[i + k] == 'o'))
				&& ((gameBoardArray[i + 1 + k] == 'A') || (gameBoardArray[i + 1 + k] == 'E') || (gameBoardArray[i + 1 + k] == 'I') || (gameBoardArray[i + 1 + k] == 'O') || (gameBoardArray[i + 1 + k] == 'a') || (gameBoardArray[i + 1 + k] == 'e') || (gameBoardArray[i + 1 + k] == 'i') || (gameBoardArray[i + 1 + k] == 'o'))
				&& ((gameBoardArray[i + 4 + k] == 'A') || (gameBoardArray[i + 4 + k] == 'E') || (gameBoardArray[i + 4 + k] == 'I') || (gameBoardArray[i + 4 + k] == 'O') || (gameBoardArray[i + 4 + k] == 'a') || (gameBoardArray[i + 4 + k] == 'e') || (gameBoardArray[i + 4 + k] == 'i') || (gameBoardArray[i + 4 + k] == 'o'))
				&& ((gameBoardArray[i + 5 + k] == 'A') || (gameBoardArray[i + 5 + k] == 'E') || (gameBoardArray[i + 5 + k] == 'I') || (gameBoardArray[i + 5 + k] == 'O') || (gameBoardArray[i + 5 + k] == 'a') || (gameBoardArray[i + 5 + k] == 'e') || (gameBoardArray[i + 5 + k] == 'i') || (gameBoardArray[i + 5 + k] == 'o'))) {
				return TRUE;
			}

			//Declares win for TOP corners for upper case
			if (((gameBoardArray[i + k] == 'A') || (gameBoardArray[i + k] == 'E') || (gameBoardArray[i + k] == 'I') || (gameBoardArray[i + k] == 'O') || (gameBoardArray[i + k] == 'B') || (gameBoardArray[i + k] == 'C') || (gameBoardArray[i + k] == 'D') || (gameBoardArray[i + k] == 'F'))
				&& ((gameBoardArray[i + 1 + k] == 'A') || (gameBoardArray[i + 1 + k] == 'E') || (gameBoardArray[i + 1 + k] == 'I') || (gameBoardArray[i + 1 + k] == 'O') || (gameBoardArray[i + 1 + k] == 'B') || (gameBoardArray[i + 1 + k] == 'C') || (gameBoardArray[i + 1 + k] == 'D') || (gameBoardArray[i + 1 + k] == 'F'))
				&& ((gameBoardArray[i + 4 + k] == 'A') || (gameBoardArray[i + 4 + k] == 'E') || (gameBoardArray[i + 4 + k] == 'I') || (gameBoardArray[i + 4 + k] == 'O') || (gameBoardArray[i + 4 + k] == 'B') || (gameBoardArray[i + 4 + k] == 'C') || (gameBoardArray[i + 4 + k] == 'D') || (gameBoardArray[i + 4 + k] == 'F'))
				&& ((gameBoardArray[i + 5 + k] == 'A') || (gameBoardArray[i + 5 + k] == 'E') || (gameBoardArray[i + 5 + k] == 'I') || (gameBoardArray[i + 5 + k] == 'O') || (gameBoardArray[i + 5 + k] == 'B') || (gameBoardArray[i + 5 + k] == 'C') || (gameBoardArray[i + 5 + k] == 'D') || (gameBoardArray[i + 5 + k] == 'F'))) {
				return TRUE;
			}

			//Declares win for TOP corners for lower case
			if (((gameBoardArray[i + k] == 'a') || (gameBoardArray[i + k] == 'e') || (gameBoardArray[i + k] == 'i') || (gameBoardArray[i + k] == 'o') || (gameBoardArray[i + k] == 'b') || (gameBoardArray[i + k] == 'c') || (gameBoardArray[i + k] == 'd') || (gameBoardArray[i + k] == 'f'))
				&& ((gameBoardArray[i + 1 + k] == 'a') || (gameBoardArray[i + 1 + k] == 'e') || (gameBoardArray[i + 1 + k] == 'i') || (gameBoardArray[i + 1 + k] == 'o') || (gameBoardArray[i + 1 + k] == 'b') || (gameBoardArray[i + 1 + k] == 'c') || (gameBoardArray[i + 1 + k] == 'd') || (gameBoardArray[i + 1 + k] == 'f'))
				&& ((gameBoardArray[i + 4 + k] == 'a') || (gameBoardArray[i + 4 + k] == 'e') || (gameBoardArray[i + 4 + k] == 'i') || (gameBoardArray[i + 4 + k] == 'o') || (gameBoardArray[i + 4 + k] == 'b') || (gameBoardArray[i + 4 + k] == 'c') || (gameBoardArray[i + 4 + k] == 'd') || (gameBoardArray[i + 4 + k] == 'f'))
				&& ((gameBoardArray[i + 5 + k] == 'a') || (gameBoardArray[i + 5 + k] == 'e') || (gameBoardArray[i + 5 + k] == 'i') || (gameBoardArray[i + 5 + k] == 'o') || (gameBoardArray[i + 5 + k] == 'b') || (gameBoardArray[i + 5 + k] == 'c') || (gameBoardArray[i + 5 + k] == 'd') || (gameBoardArray[i + 5 + k] == 'f'))) {
				return TRUE;
			}

		}
	}
	return FALSE;
}

//Creating function that will check for winnnigs if the LEVEL is 2. This will check BOTTOM CORNERS. Returns TRUE if a winning is found in those sections and returns FALSE if no winning is found
int LevelWinnings2BottomCorners(char gameBoardArray[]) {

	for (int k = 0; k <= 3; k = k + 2) {
		for (int i = 0; i < 1; i++) {

			//Declares win for BOTTOM corners for upper case and lower case CONSONANTS
			if (((gameBoardArray[i + k + 8] == 'F') || (gameBoardArray[i + k + 8] == 'B') || (gameBoardArray[i + k + 8] == 'C') || (gameBoardArray[i + k + 8] == 'D') || (gameBoardArray[i + k + 8] == 'b') || (gameBoardArray[i + k + 8] == 'c') || (gameBoardArray[i + k + 8] == 'd') || (gameBoardArray[i + k + 8] == 'f'))
				&& ((gameBoardArray[i + k + 9] == 'B') || (gameBoardArray[i + k + 9] == 'C') || (gameBoardArray[i + k + 9] == 'D') || (gameBoardArray[i + k + 9] == 'F') || (gameBoardArray[i + k + 9] == 'b') || (gameBoardArray[i + k + 9] == 'c') || (gameBoardArray[i + k + 9] == 'd') || (gameBoardArray[i + k + 9] == 'f'))
				&& ((gameBoardArray[i + 12 + k] == 'B') || (gameBoardArray[i + 12 + k] == 'C') || (gameBoardArray[i + 12 + k] == 'D') || (gameBoardArray[i + 12 + k] == 'F') || (gameBoardArray[i + 12 + k] == 'b') || (gameBoardArray[i + 12 + k] == 'c') || (gameBoardArray[i + 12 + k] == 'd') || (gameBoardArray[i + 12 + k] == 'f'))
				&& ((gameBoardArray[i + 13 + k] == 'B') || (gameBoardArray[i + 13 + k] == 'C') || (gameBoardArray[i + 13 + k] == 'D') || (gameBoardArray[i + 13 + k] == 'F') || (gameBoardArray[i + 13 + k] == 'b') || (gameBoardArray[i + 13 + k] == 'c') || (gameBoardArray[i + 13 + k] == 'd') || (gameBoardArray[i + 13 + k] == 'f'))) {
				return TRUE;
			}

			//Declares win for BOTTOM corners for upper case and lower case VOWELS
			if (((gameBoardArray[i + k + 8] == 'A') || (gameBoardArray[i + k + 8] == 'E') || (gameBoardArray[i + k + 8] == 'I') || (gameBoardArray[i + k + 8] == 'O') || (gameBoardArray[i + k + 8] == 'a') || (gameBoardArray[i + k + 8] == 'e') || (gameBoardArray[i + k + 8] == 'i') || (gameBoardArray[i + k + 8] == 'o'))
				&& ((gameBoardArray[i + k + 9] == 'A') || (gameBoardArray[i + k + 9] == 'E') || (gameBoardArray[i + k + 9] == 'I') || (gameBoardArray[i + k + 9] == 'O') || (gameBoardArray[i + k + 9] == 'a') || (gameBoardArray[i + k + 9] == 'e') || (gameBoardArray[i + k + 9] == 'i') || (gameBoardArray[i + k + 9] == 'o'))
				&& ((gameBoardArray[i + 12 + k] == 'A') || (gameBoardArray[i + 12 + k] == 'E') || (gameBoardArray[i + 12 + k] == 'I') || (gameBoardArray[i + 12 + k] == 'O') || (gameBoardArray[i + 12 + k] == 'a') || (gameBoardArray[i + 12 + k] == 'e') || (gameBoardArray[i + 12 + k] == 'i') || (gameBoardArray[i + 12 + k] == 'o'))
				&& ((gameBoardArray[i + 13 + k] == 'A') || (gameBoardArray[i + 13 + k] == 'E') || (gameBoardArray[i + 13 + k] == 'I') || (gameBoardArray[i + 13 + k] == 'O') || (gameBoardArray[i + 13 + k] == 'a') || (gameBoardArray[i + 13 + k] == 'e') || (gameBoardArray[i + 13 + k] == 'i') || (gameBoardArray[i + 13 + k] == 'o'))) {
				return TRUE;
			}
			//Declares win for BOTTOM corners if are upper case.
			if (((gameBoardArray[i + k + 8] == 'A') || (gameBoardArray[i + k + 8] == 'E') || (gameBoardArray[i + k + 8] == 'I') || (gameBoardArray[i + k + 8] == 'O') || (gameBoardArray[i + k + 8] == 'B') || (gameBoardArray[i + k + 8] == 'C') || (gameBoardArray[i + k + 8] == 'D') || (gameBoardArray[i + k + 8] == 'F'))
				&& ((gameBoardArray[i + k + 9] == 'A') || (gameBoardArray[i + k + 9] == 'E') || (gameBoardArray[i + k + 9] == 'I') || (gameBoardArray[i + k + 9] == 'O') || (gameBoardArray[i + k + 9] == 'B') || (gameBoardArray[i + k + 9] == 'C') || (gameBoardArray[i + k + 9] == 'D') || (gameBoardArray[i + k + 9] == 'F'))
				&& ((gameBoardArray[i + 12 + k] == 'A') || (gameBoardArray[i + 12 + k] == 'E') || (gameBoardArray[i + 12 + k] == 'I') || (gameBoardArray[i + 12 + k] == 'O') || (gameBoardArray[i + 12 + k] == 'B') || (gameBoardArray[i + 12 + k] == 'C') || (gameBoardArray[i + 12 + k] == 'D') || (gameBoardArray[i + 12 + k] == 'F'))
				&& ((gameBoardArray[i + 13 + k] == 'A') || (gameBoardArray[i + 13 + k] == 'E') || (gameBoardArray[i + 13 + k] == 'I') || (gameBoardArray[i + 13 + k] == 'O') || (gameBoardArray[i + 13 + k] == 'B') || (gameBoardArray[i + 13 + k] == 'C') || (gameBoardArray[i + 13 + k] == 'D') || (gameBoardArray[i + 13 + k] == 'F'))) {
				return TRUE;
			}

			//Declares win for BOTTOM corners if are lower case.
			if (((gameBoardArray[i + k + 8] == 'a') || (gameBoardArray[i + k + 8] == 'e') || (gameBoardArray[i + k + 8] == 'i') || (gameBoardArray[i + k + 8] == 'o') || (gameBoardArray[i + k + 8] == 'b') || (gameBoardArray[i + k + 8] == 'c') || (gameBoardArray[i + k + 8] == 'd') || (gameBoardArray[i + k + 8] == 'f'))
				&& ((gameBoardArray[i + k + 9] == 'a') || (gameBoardArray[i + k + 9] == 'e') || (gameBoardArray[i + k + 9] == 'i') || (gameBoardArray[i + k + 9] == 'o') || (gameBoardArray[i + k + 9] == 'b') || (gameBoardArray[i + k + 9] == 'c') || (gameBoardArray[i + k + 9] == 'd') || (gameBoardArray[i + k + 9] == 'f'))
				&& ((gameBoardArray[i + 12 + k] == 'a') || (gameBoardArray[i + 12 + k] == 'e') || (gameBoardArray[i + 12 + k] == 'i') || (gameBoardArray[i + 12 + k] == 'o') || (gameBoardArray[i + 12 + k] == 'b') || (gameBoardArray[i + 12 + k] == 'c') || (gameBoardArray[i + 12 + k] == 'd') || (gameBoardArray[i + 12 + k] == 'f'))
				&& ((gameBoardArray[i + 13 + k] == 'a') || (gameBoardArray[i + 13 + k] == 'e') || (gameBoardArray[i + 13 + k] == 'i') || (gameBoardArray[i + 13 + k] == 'o') || (gameBoardArray[i + 13 + k] == 'b') || (gameBoardArray[i + 13 + k] == 'c') || (gameBoardArray[i + 13 + k] == 'd') || (gameBoardArray[i + 13 + k] == 'f'))) {
				return TRUE;
			}
		}
	}

	return FALSE;
}

//Creating Function that will the four corners of the whole gameboardarray if the LEVEL is 2, returning TRUE is a win is found and returning FALSE is no win is found
int checkLevel2ALLCorners(char gameBoardArray[]) {
	for (int i = 0; i < 1; i++) {

		//Declares win is all are vowels
		if (((gameBoardArray[i] == 'A') || (gameBoardArray[i] == 'E') || (gameBoardArray[i] == 'I') || (gameBoardArray[i] == 'O') || (gameBoardArray[i] == 'a') || (gameBoardArray[i] == 'e') || (gameBoardArray[i] == 'i') || (gameBoardArray[i] == 'o'))
			&& ((gameBoardArray[i + 3] == 'A') || (gameBoardArray[i + 3] == 'E') || (gameBoardArray[i + 3] == 'I') || (gameBoardArray[i + 3] == 'O') || (gameBoardArray[i + 3] == 'a') || (gameBoardArray[i + 3] == 'e') || (gameBoardArray[i + 3] == 'i') || (gameBoardArray[i + 3] == 'o'))
			&& ((gameBoardArray[i + 12] == 'A') || (gameBoardArray[i + 12] == 'E') || (gameBoardArray[i + 12] == 'I') || (gameBoardArray[i + 12] == 'O') || (gameBoardArray[i + 12] == 'a') || (gameBoardArray[i + 12] == 'e') || (gameBoardArray[i + 12] == 'i') || (gameBoardArray[i + 12] == 'o'))
			&& ((gameBoardArray[i + 15] == 'A') || (gameBoardArray[i + 15] == 'E') || (gameBoardArray[i + 15] == 'I') || (gameBoardArray[i + 15] == 'O') || (gameBoardArray[i + 15] == 'a') || (gameBoardArray[i + 15] == 'e') || (gameBoardArray[i + 15] == 'i') || (gameBoardArray[i + 15] == 'o'))) {
			return TRUE;
		}

		//Declares win is all are Upper case
		if (((gameBoardArray[i] == 'A') || (gameBoardArray[i] == 'E') || (gameBoardArray[i] == 'I') || (gameBoardArray[i] == 'O') || (gameBoardArray[i] == 'B') || (gameBoardArray[i] == 'C') || (gameBoardArray[i] == 'D') || (gameBoardArray[i] == 'F'))
			&& ((gameBoardArray[i + 3] == 'A') || (gameBoardArray[i + 3] == 'E') || (gameBoardArray[i + 3] == 'I') || (gameBoardArray[i + 3] == 'O') || (gameBoardArray[i + 3] == 'B') || (gameBoardArray[i + 3] == 'C') || (gameBoardArray[i + 3] == 'D') || (gameBoardArray[i + 3] == 'F'))
			&& ((gameBoardArray[i + 12] == 'A') || (gameBoardArray[i + 12] == 'E') || (gameBoardArray[i + 12] == 'I') || (gameBoardArray[i + 12] == 'O') || (gameBoardArray[i + 12] == 'B') || (gameBoardArray[i + 12] == 'C') || (gameBoardArray[i + 12] == 'D') || (gameBoardArray[i + 12] == 'F'))
			&& ((gameBoardArray[i + 15] == 'A') || (gameBoardArray[i + 15] == 'E') || (gameBoardArray[i + 15] == 'I') || (gameBoardArray[i + 15] == 'O') || (gameBoardArray[i + 15] == 'B') || (gameBoardArray[i + 15] == 'C') || (gameBoardArray[i + 15] == 'D') || (gameBoardArray[i + 15] == 'F'))) {
			return TRUE;
		}

		//Declares win is all are lower case
		if (((gameBoardArray[i] == 'b') || (gameBoardArray[i] == 'c') || (gameBoardArray[i] == 'd') || (gameBoardArray[i] == 'f') || (gameBoardArray[i] == 'a') || (gameBoardArray[i] == 'e') || (gameBoardArray[i] == 'i') || (gameBoardArray[i] == 'o'))
			&& ((gameBoardArray[i + 3] == 'b') || (gameBoardArray[i + 3] == 'c') || (gameBoardArray[i + 3] == 'd') || (gameBoardArray[i + 3] == 'f') || (gameBoardArray[i + 3] == 'a') || (gameBoardArray[i + 3] == 'e') || (gameBoardArray[i + 3] == 'i') || (gameBoardArray[i + 3] == 'o'))
			&& ((gameBoardArray[i + 12] == 'b') || (gameBoardArray[i + 12] == 'c') || (gameBoardArray[i + 12] == 'd') || (gameBoardArray[i + 12] == 'f') || (gameBoardArray[i + 12] == 'a') || (gameBoardArray[i + 12] == 'e') || (gameBoardArray[i + 12] == 'i') || (gameBoardArray[i + 12] == 'o'))
			&& ((gameBoardArray[i + 15] == 'b') || (gameBoardArray[i + 15] == 'c') || (gameBoardArray[i + 15] == 'd') || (gameBoardArray[i + 15] == 'f') || (gameBoardArray[i + 15] == 'a') || (gameBoardArray[i + 15] == 'e') || (gameBoardArray[i + 15] == 'i') || (gameBoardArray[i + 15] == 'o'))) {
			return TRUE;
		}

		//Declares win is all are Consonants
		if (((gameBoardArray[i] == 'b') || (gameBoardArray[i] == 'c') || (gameBoardArray[i] == 'd') || (gameBoardArray[i] == 'f') || (gameBoardArray[i] == 'B') || (gameBoardArray[i] == 'C') || (gameBoardArray[i] == 'D') || (gameBoardArray[i] == 'F'))
			&& ((gameBoardArray[i + 3] == 'b') || (gameBoardArray[i + 3] == 'c') || (gameBoardArray[i + 3] == 'd') || (gameBoardArray[i + 3] == 'f') || (gameBoardArray[i + 3] == 'B') || (gameBoardArray[i + 3] == 'C') || (gameBoardArray[i + 3] == 'D') || (gameBoardArray[i + 3] == 'F'))
			&& ((gameBoardArray[i + 12] == 'b') || (gameBoardArray[i + 12] == 'c') || (gameBoardArray[i + 12] == 'd') || (gameBoardArray[i + 12] == 'f') || (gameBoardArray[i + 12] == 'B') || (gameBoardArray[i + 12] == 'C') || (gameBoardArray[i + 12] == 'D') || (gameBoardArray[i + 12] == 'F'))
			&& ((gameBoardArray[i + 15] == 'b') || (gameBoardArray[i + 15] == 'c') || (gameBoardArray[i + 15] == 'd') || (gameBoardArray[i + 15] == 'f') || (gameBoardArray[i + 15] == 'B') || (gameBoardArray[i + 15] == 'C') || (gameBoardArray[i + 15] == 'D') || (gameBoardArray[i + 15] == 'F'))) {
			return TRUE;
		}


	}
	//*************************

	return FALSE;
}

//Creating function that will the TRUE and FALSE value of each of the winning functions for LEVEL 2
int LevelWinnings2(char gameBoardArray[17]) {

	if (Level2TopCorners(gameBoardArray) == TRUE) {
		return TRUE;
	}
	if (LevelWinnings2BottomCorners(gameBoardArray) == TRUE) {
		return TRUE;
	}
	if (checkLevel2ALLCorners(gameBoardArray)) {
		return TRUE;
	}
	return FALSE;
}


//Creating functiont that will check winnings for Columns in LEVEL 1, Returns TRUE if a win is found and returns False is no win is found.
int CheckColumnsWinnings(char gameBoardArray[]) {
	// Checks all columns for wins
	for (int k = 0; k <= 3; k = k + 1) {
		for (int i = 0; i < 1; i++) {

			//Check if all upper case
			if (((gameBoardArray[i + k] == 'O') || (gameBoardArray[i + k] == 'A') || (gameBoardArray[i + k] == 'E') || (gameBoardArray[i + k] == 'I') || (gameBoardArray[i + k] == 'F') || (gameBoardArray[i + k] == 'B') || (gameBoardArray[i + k] == 'C') || (gameBoardArray[i + k] == 'D'))
				&& ((gameBoardArray[i + 4 + k] == 'O') || (gameBoardArray[i + 4 + k] == 'A') || (gameBoardArray[i + 4 + k] == 'E') || (gameBoardArray[i + 4 + k] == 'I') || (gameBoardArray[i + 4 + k] == 'B') || (gameBoardArray[i + 4 + k] == 'C') || (gameBoardArray[i + 4 + k] == 'D') || (gameBoardArray[i + 4 + k] == 'F'))
				&& ((gameBoardArray[i + 8 + k] == 'O') || (gameBoardArray[i + 8 + k] == 'A') || (gameBoardArray[i + 8 + k] == 'E') || (gameBoardArray[i + 8 + k] == 'I') || (gameBoardArray[i + 8 + k] == 'B') || (gameBoardArray[i + 8 + k] == 'C') || (gameBoardArray[i + 8 + k] == 'D') || (gameBoardArray[i + 8 + k] == 'F'))
				&& ((gameBoardArray[i + 12 + k] == 'O') || (gameBoardArray[i + 12 + k] == 'A') || (gameBoardArray[i + 12 + k] == 'E') || (gameBoardArray[i + 12 + k] == 'I') || (gameBoardArray[i + 12 + k] == 'B') || (gameBoardArray[i + 12 + k] == 'C') || (gameBoardArray[i + 12 + k] == 'D') || (gameBoardArray[i + 12 + k] == 'F'))) {
				return TRUE;
			}

			//Check if all lower case
			if (((gameBoardArray[i + k] == 'a') || (gameBoardArray[i + k] == 'e') || (gameBoardArray[i + k] == 'i') || (gameBoardArray[i + k] == 'o') || (gameBoardArray[i + k] == 'b') || (gameBoardArray[i + k] == 'c') || (gameBoardArray[i + k] == 'd') || (gameBoardArray[i + k] == 'f'))
				&& ((gameBoardArray[i + 4 + k] == 'a') || (gameBoardArray[i + 4 + k] == 'e') || (gameBoardArray[i + 4 + k] == 'i') || (gameBoardArray[i + 4 + k] == 'o') || (gameBoardArray[i + 4 + k] == 'b') || (gameBoardArray[i + 4 + k] == 'c') || (gameBoardArray[i + 4 + k] == 'd') || (gameBoardArray[i + 4 + k] == 'f'))
				&& ((gameBoardArray[i + 8 + k] == 'a') || (gameBoardArray[i + 8 + k] == 'e') || (gameBoardArray[i + 8 + k] == 'i') || (gameBoardArray[i + 8 + k] == 'o') || (gameBoardArray[i + 8 + k] == 'b') || (gameBoardArray[i + 8 + k] == 'c') || (gameBoardArray[i + 8 + k] == 'd') || (gameBoardArray[i + 8 + k] == 'f'))
				&& ((gameBoardArray[i + 12 + k] == 'a') || (gameBoardArray[i + 12 + k] == 'e') || (gameBoardArray[i + 12 + k] == 'i') || (gameBoardArray[i + 12 + k] == 'o') || (gameBoardArray[i + 12 + k] == 'b') || (gameBoardArray[i + 12 + k] == 'c') || (gameBoardArray[i + 12 + k] == 'd') || (gameBoardArray[i + 12 + k] == 'f'))) {
				return TRUE;
			}

			//Check if all vowels
			if (((gameBoardArray[i + k] == 'A') || (gameBoardArray[i + k] == 'E') || (gameBoardArray[i + k] == 'I') || (gameBoardArray[i + k] == 'O') || (gameBoardArray[i + k] == 'a') || (gameBoardArray[i + k] == 'e') || (gameBoardArray[i + k] == 'i') || (gameBoardArray[i + k] == 'o'))
				&& ((gameBoardArray[i + 4 + k] == 'A') || (gameBoardArray[i + 4 + k] == 'E') || (gameBoardArray[i + 4 + k] == 'I') || (gameBoardArray[i + 4 + k] == 'O') || (gameBoardArray[i + 4 + k] == 'a') || (gameBoardArray[i + 4 + k] == 'e') || (gameBoardArray[i + 4 + k] == 'i') || (gameBoardArray[i + 4 + k] == 'o'))
				&& ((gameBoardArray[i + 8 + k] == 'A') || (gameBoardArray[i + 8 + k] == 'E') || (gameBoardArray[i + 8 + k] == 'I') || (gameBoardArray[i + 8 + k] == 'O') || (gameBoardArray[i + 8 + k] == 'a') || (gameBoardArray[i + 8 + k] == 'e') || (gameBoardArray[i + 8 + k] == 'i') || (gameBoardArray[i + 8 + k] == 'o'))
				&& ((gameBoardArray[i + 12 + k] == 'A') || (gameBoardArray[i + 12 + k] == 'E') || (gameBoardArray[i + 12 + k] == 'I') || (gameBoardArray[i + 12 + k] == 'O') || (gameBoardArray[i + 12 + k] == 'a') || (gameBoardArray[i + 12 + k] == 'e') || (gameBoardArray[i + 12 + k] == 'i') || (gameBoardArray[i + 12 + k] == 'o'))) {
				return TRUE;
			}

			//Check if all Consonants
			if (((gameBoardArray[i + k] == 'B') || (gameBoardArray[i + k] == 'C') || (gameBoardArray[i + k] == 'D') || (gameBoardArray[i + k] == 'F') || (gameBoardArray[i + k] == 'b') || (gameBoardArray[i + k] == 'c') || (gameBoardArray[i + k] == 'd') || (gameBoardArray[i + k] == 'f'))
				&& ((gameBoardArray[i + 4 + k] == 'B') || (gameBoardArray[i + 4 + k] == 'C') || (gameBoardArray[i + 4 + k] == 'D') || (gameBoardArray[i + 4 + k] == 'F') || (gameBoardArray[i + 4 + k] == 'b') || (gameBoardArray[i + 4 + k] == 'c') || (gameBoardArray[i + 4 + k] == 'd') || (gameBoardArray[i + 4 + k] == 'f'))
				&& ((gameBoardArray[i + 8 + k] == 'B') || (gameBoardArray[i + 8 + k] == 'C') || (gameBoardArray[i + 8 + k] == 'D') || (gameBoardArray[i + 8 + k] == 'F') || (gameBoardArray[i + 8 + k] == 'b') || (gameBoardArray[i + 8 + k] == 'c') || (gameBoardArray[i + 8 + k] == 'd') || (gameBoardArray[i + 8 + k] == 'f'))
				&& ((gameBoardArray[i + 12 + k] == 'B') || (gameBoardArray[i + 12 + k] == 'C') || (gameBoardArray[i + 12 + k] == 'D') || (gameBoardArray[i + 12 + k] == 'F') || (gameBoardArray[i + 12 + k] == 'b') || (gameBoardArray[i + 12 + k] == 'c') || (gameBoardArray[i + 12 + k] == 'd') || (gameBoardArray[i + 12 + k] == 'f'))) {
				return TRUE;
			}
		}
	}
	return FALSE;

}

//Function that will check for wins in the rows for LEVEL 1, Returns TRUE if a win is found, returns FALSE is no win is found
int CheckRowWinnings(char gameBoardArray[]) {
	for (int k = 0; k <= 12; k = k + 4) {
		for (int i = 0; i < 1; i++) {
			//check upper case
			if (((gameBoardArray[i + k] == 'O') || (gameBoardArray[i + k] == 'A') || (gameBoardArray[i + k] == 'E') || (gameBoardArray[i + k] == 'I') || (gameBoardArray[i + k] == 'F') || (gameBoardArray[i + k] == 'B') || (gameBoardArray[i + k] == 'C') || (gameBoardArray[i + k] == 'D'))
				&& ((gameBoardArray[i + 1 + k] == 'O') || (gameBoardArray[i + 1 + k] == 'A') || (gameBoardArray[i + 1 + k] == 'E') || (gameBoardArray[i + 1 + k] == 'I') || (gameBoardArray[i + 1 + k] == 'B') || (gameBoardArray[i + 1 + k] == 'C') || (gameBoardArray[i + 1 + k] == 'D') || (gameBoardArray[i + 1 + k] == 'F'))
				&& ((gameBoardArray[i + 2 + k] == 'O') || (gameBoardArray[i + 2 + k] == 'A') || (gameBoardArray[i + 2 + k] == 'E') || (gameBoardArray[i + 2 + k] == 'I') || (gameBoardArray[i + 2 + k] == 'B') || (gameBoardArray[i + 2 + k] == 'C') || (gameBoardArray[i + 2 + k] == 'D') || (gameBoardArray[i + 2 + k] == 'F'))
				&& ((gameBoardArray[i + 3 + k] == 'O') || (gameBoardArray[i + 3 + k] == 'A') || (gameBoardArray[i + 3 + k] == 'E') || (gameBoardArray[i + 3 + k] == 'I') || (gameBoardArray[i + 3 + k] == 'B') || (gameBoardArray[i + 3 + k] == 'C') || (gameBoardArray[i + 3 + k] == 'D') || (gameBoardArray[i + 3 + k] == 'F'))) {

				return TRUE;
			}
			//Check Lowercase Letters
			if (((gameBoardArray[i + k] == 'a') || (gameBoardArray[i + k] == 'e') || (gameBoardArray[i + k] == 'i') || (gameBoardArray[i + k] == 'o') || (gameBoardArray[i + k] == 'b') || (gameBoardArray[i + k] == 'c') || (gameBoardArray[i + k] == 'd') || (gameBoardArray[i + k] == 'f'))
				&& ((gameBoardArray[i + 1 + k] == 'a') || (gameBoardArray[i + 1 + k] == 'e') || (gameBoardArray[i + 1 + k] == 'i') || (gameBoardArray[i + 1 + k] == 'o') || (gameBoardArray[i + 1 + k] == 'b') || (gameBoardArray[i + 1 + k] == 'c') || (gameBoardArray[i + 1 + k] == 'd') || (gameBoardArray[i + 1 + k] == 'f'))
				&& ((gameBoardArray[i + 2 + k] == 'a') || (gameBoardArray[i + 2 + k] == 'e') || (gameBoardArray[i + 2 + k] == 'i') || (gameBoardArray[i + 2 + k] == 'o') || (gameBoardArray[i + 2 + k] == 'b') || (gameBoardArray[i + 2 + k] == 'c') || (gameBoardArray[i + 2 + k] == 'd') || (gameBoardArray[i + 2 + k] == 'f'))
				&& ((gameBoardArray[i + 3 + k] == 'a') || (gameBoardArray[i + 3 + k] == 'e') || (gameBoardArray[i + 3 + k] == 'i') || (gameBoardArray[i + 3 + k] == 'o') || (gameBoardArray[i + 3 + k] == 'b') || (gameBoardArray[i + 3 + k] == 'c') || (gameBoardArray[i + 3 + k] == 'd') || (gameBoardArray[i + 3 + k] == 'f'))) {
				return TRUE;
			}
			//Check Vowels
			if (((gameBoardArray[i + k] == 'A') || (gameBoardArray[i + k] == 'E') || (gameBoardArray[i + k] == 'I') || (gameBoardArray[i + k] == 'O') || (gameBoardArray[i + k] == 'a') || (gameBoardArray[i + k] == 'e') || (gameBoardArray[i + k] == 'i') || (gameBoardArray[i + k] == 'o'))
				&& ((gameBoardArray[i + 1 + k] == 'A') || (gameBoardArray[i + 1 + k] == 'E') || (gameBoardArray[i + 1 + k] == 'I') || (gameBoardArray[i + 1 + k] == 'O') || (gameBoardArray[i + 1 + k] == 'a') || (gameBoardArray[i + 1 + k] == 'e') || (gameBoardArray[i + 1 + k] == 'i') || (gameBoardArray[i + 1 + k] == 'o'))
				&& ((gameBoardArray[i + 2 + k] == 'A') || (gameBoardArray[i + 2 + k] == 'E') || (gameBoardArray[i + 2 + k] == 'I') || (gameBoardArray[i + 2 + k] == 'O') || (gameBoardArray[i + 2 + k] == 'a') || (gameBoardArray[i + 2 + k] == 'e') || (gameBoardArray[i + 2 + k] == 'i') || (gameBoardArray[i + 2 + k] == 'o'))
				&& ((gameBoardArray[i + 3 + k] == 'A') || (gameBoardArray[i + 3 + k] == 'E') || (gameBoardArray[i + 3 + k] == 'I') || (gameBoardArray[i + 3 + k] == 'O') || (gameBoardArray[i + 3 + k] == 'a') || (gameBoardArray[i + 3 + k] == 'e') || (gameBoardArray[i + 3 + k] == 'i') || (gameBoardArray[i + 3 + k] == 'o'))) {
				return TRUE;
			}

			//Check Consonants
			if (((gameBoardArray[i + k] == 'B') || (gameBoardArray[i + k] == 'C') || (gameBoardArray[i + k] == 'D') || (gameBoardArray[i + k] == 'F') || (gameBoardArray[i + k] == 'b') || (gameBoardArray[i + k] == 'c') || (gameBoardArray[i + k] == 'd') || (gameBoardArray[i + k] == 'f'))
				&& ((gameBoardArray[i + 1 + k] == 'B') || (gameBoardArray[i + 1 + k] == 'C') || (gameBoardArray[i + 1 + k] == 'D') || (gameBoardArray[i + 1 + k] == 'F') || (gameBoardArray[i + 1 + k] == 'b') || (gameBoardArray[i + 1 + k] == 'c') || (gameBoardArray[i + 1 + k] == 'd') || (gameBoardArray[i + 1 + k] == 'f'))
				&& ((gameBoardArray[i + 2 + k] == 'B') || (gameBoardArray[i + 2 + k] == 'C') || (gameBoardArray[i + 2 + k] == 'D') || (gameBoardArray[i + 2 + k] == 'F') || (gameBoardArray[i + 2 + k] == 'b') || (gameBoardArray[i + 2 + k] == 'c') || (gameBoardArray[i + 2 + k] == 'd') || (gameBoardArray[i + 2 + k] == 'f'))
				&& ((gameBoardArray[i + 3 + k] == 'B') || (gameBoardArray[i + 3 + k] == 'C') || (gameBoardArray[i + 3 + k] == 'D') || (gameBoardArray[i + 3 + k] == 'F') || (gameBoardArray[i + 3 + k] == 'b') || (gameBoardArray[i + 3 + k] == 'c') || (gameBoardArray[i + 3 + k] == 'd') || (gameBoardArray[i + 3 + k] == 'f'))) {
				return TRUE;
			}
		}
	}
	return FALSE;
}

//Function to check diagonal for LEVEl 1, returns TRUE is win is found, returns FALSE if no win is found
int CheckFirstDiagonal(char gameBoardArray[]) {
	//First Diagnal
	for (int i = 0; i < 1; i++) {
		//check capitals
		if (((gameBoardArray[i] == 'O') || (gameBoardArray[i] == 'A') || (gameBoardArray[i] == 'E') || (gameBoardArray[i] == 'I') || (gameBoardArray[i] == 'F') || (gameBoardArray[i] == 'B') || (gameBoardArray[i] == 'C') || (gameBoardArray[i] == 'D'))
			&& ((gameBoardArray[i + 5] == 'O') || (gameBoardArray[i + 5] == 'A') || (gameBoardArray[i + 5] == 'E') || (gameBoardArray[i + 5] == 'I') || (gameBoardArray[i + 5] == 'B') || (gameBoardArray[i + 5] == 'C') || (gameBoardArray[i + 5] == 'D') || (gameBoardArray[i + 5] == 'F'))
			&& ((gameBoardArray[i + 10] == 'O') || (gameBoardArray[i + 10] == 'A') || (gameBoardArray[i + 10] == 'E') || (gameBoardArray[i + 10] == 'I') || (gameBoardArray[i + 10] == 'B') || (gameBoardArray[i + 10] == 'C') || (gameBoardArray[i + 10] == 'D') || (gameBoardArray[i + 10] == 'F'))
			&& ((gameBoardArray[i + 15] == 'O') || (gameBoardArray[i + 15] == 'A') || (gameBoardArray[i + 15] == 'E') || (gameBoardArray[i + 15] == 'I') || (gameBoardArray[i + 15] == 'B') || (gameBoardArray[i + 15] == 'C') || (gameBoardArray[i + 15] == 'D') || (gameBoardArray[i + 15] == 'F'))) {
			return TRUE;
		}

		//check lowercase
		if (((gameBoardArray[i] == 'a') || (gameBoardArray[i] == 'e') || (gameBoardArray[i] == 'i') || (gameBoardArray[i] == 'o') || (gameBoardArray[i] == 'b') || (gameBoardArray[i] == 'c') || (gameBoardArray[i] == 'd') || (gameBoardArray[i] == 'f'))
			&& ((gameBoardArray[i + 5] == 'a') || (gameBoardArray[i + 5] == 'e') || (gameBoardArray[i + 5] == 'i') || (gameBoardArray[i + 5] == 'o') || (gameBoardArray[i + 5] == 'b') || (gameBoardArray[i + 5] == 'c') || (gameBoardArray[i + 5] == 'd') || (gameBoardArray[i + 5] == 'f'))
			&& ((gameBoardArray[i + 10] == 'a') || (gameBoardArray[i + 10] == 'e') || (gameBoardArray[i + 10] == 'i') || (gameBoardArray[i + 10] == 'o') || (gameBoardArray[i + 10] == 'b') || (gameBoardArray[i + 10] == 'c') || (gameBoardArray[i + 10] == 'd') || (gameBoardArray[i + 10] == 'f'))
			&& ((gameBoardArray[i + 15] == 'a') || (gameBoardArray[i + 15] == 'e') || (gameBoardArray[i + 15] == 'i') || (gameBoardArray[i + 15] == 'o') || (gameBoardArray[i + 15] == 'b') || (gameBoardArray[i + 15] == 'c') || (gameBoardArray[i + 15] == 'd') || (gameBoardArray[i + 15] == 'f'))) {
			return TRUE;
		}
		//Check vowels
		if (((gameBoardArray[i] == 'A') || (gameBoardArray[i] == 'E') || (gameBoardArray[i] == 'I') || (gameBoardArray[i] == 'O') || (gameBoardArray[i] == 'a') || (gameBoardArray[i] == 'e') || (gameBoardArray[i] == 'i') || (gameBoardArray[i] == 'o'))
			&& ((gameBoardArray[i + 5] == 'A') || (gameBoardArray[i + 5] == 'E') || (gameBoardArray[i + 5] == 'I') || (gameBoardArray[i + 5] == 'O') || (gameBoardArray[i + 5] == 'a') || (gameBoardArray[i + 5] == 'e') || (gameBoardArray[i + 5] == 'i') || (gameBoardArray[i + 5] == 'o'))
			&& ((gameBoardArray[i + 10] == 'A') || (gameBoardArray[i + 10] == 'E') || (gameBoardArray[i + 10] == 'I') || (gameBoardArray[i + 10] == 'O') || (gameBoardArray[i + 10] == 'a') || (gameBoardArray[i + 10] == 'e') || (gameBoardArray[i + 10] == 'i') || (gameBoardArray[i + 10] == 'o'))
			&& ((gameBoardArray[i + 15] == 'A') || (gameBoardArray[i + 15] == 'E') || (gameBoardArray[i + 15] == 'I') || (gameBoardArray[i + 15] == 'O') || (gameBoardArray[i + 15] == 'a') || (gameBoardArray[i + 15] == 'e') || (gameBoardArray[i + 15] == 'i') || (gameBoardArray[i + 15] == 'o'))) {
			return TRUE;
		}
		//Check consonants
		if (((gameBoardArray[i] == 'B') || (gameBoardArray[i] == 'C') || (gameBoardArray[i] == 'D') || (gameBoardArray[i] == 'F') || (gameBoardArray[i] == 'b') || (gameBoardArray[i] == 'c') || (gameBoardArray[i] == 'd') || (gameBoardArray[i] == 'f'))
			&& ((gameBoardArray[i + 5] == 'B') || (gameBoardArray[i + 5] == 'C') || (gameBoardArray[i + 5] == 'D') || (gameBoardArray[i + 5] == 'F') || (gameBoardArray[i + 5] == 'b') || (gameBoardArray[i + 5] == 'c') || (gameBoardArray[i + 5] == 'd') || (gameBoardArray[i + 5] == 'f'))
			&& ((gameBoardArray[i + 10] == 'B') || (gameBoardArray[i + 10] == 'C') || (gameBoardArray[i + 10] == 'D') || (gameBoardArray[i + 10] == 'F') || (gameBoardArray[i + 10] == 'b') || (gameBoardArray[i + 10] == 'c') || (gameBoardArray[i + 10] == 'd') || (gameBoardArray[i + 10] == 'f'))
			&& ((gameBoardArray[i + 15] == 'B') || (gameBoardArray[i + 15] == 'C') || (gameBoardArray[i + 15] == 'D') || (gameBoardArray[i + 15] == 'F') || (gameBoardArray[i + 15] == 'b') || (gameBoardArray[i + 15] == 'c') || (gameBoardArray[i + 15] == 'd') || (gameBoardArray[i + 15] == 'f'))) {
			return TRUE;
		}
	}
	return FALSE;
}

//Function to check diagonal for LEVEl 1, returns TRUE is win is found, returns FALSE if no win is found
int CheckSecondDiagonal(char gameBoardArray[]) {

	//Second Diagnal
	for (int i = 0; i < 1; i++) {
		//checks upper case
		if (((gameBoardArray[i + 3] == 'O') || (gameBoardArray[i + 3] == 'A') || (gameBoardArray[i + 3] == 'E') || (gameBoardArray[i + 3] == 'I') || (gameBoardArray[i + 3] == 'F') || (gameBoardArray[i + 3] == 'B') || (gameBoardArray[i + 3] == 'C') || (gameBoardArray[i + 3] == 'D'))
			&& ((gameBoardArray[i + 6] == 'O') || (gameBoardArray[i + 6] == 'A') || (gameBoardArray[i + 6] == 'E') || (gameBoardArray[i + 6] == 'I') || (gameBoardArray[i + 6] == 'B') || (gameBoardArray[i + 6] == 'C') || (gameBoardArray[i + 6] == 'D') || (gameBoardArray[i + 6] == 'F'))
			&& ((gameBoardArray[i + 9] == 'O') || (gameBoardArray[i + 9] == 'A') || (gameBoardArray[i + 9] == 'E') || (gameBoardArray[i + 9] == 'I') || (gameBoardArray[i + 9] == 'B') || (gameBoardArray[i + 9] == 'C') || (gameBoardArray[i + 9] == 'D') || (gameBoardArray[i + 9] == 'F'))
			&& ((gameBoardArray[i + 12] == 'O') || (gameBoardArray[i + 12] == 'A') || (gameBoardArray[i + 12] == 'E') || (gameBoardArray[i + 12] == 'I') || (gameBoardArray[i + 15] == 'B') || (gameBoardArray[i + 12] == 'C') || (gameBoardArray[i + 12] == 'D') || (gameBoardArray[i + 12] == 'F'))) {
			return TRUE;
		}
		//check lower case
		if (((gameBoardArray[i + 3] == 'a') || (gameBoardArray[i + 3] == 'e') || (gameBoardArray[i + 3] == 'i') || (gameBoardArray[i + 3] == 'o') || (gameBoardArray[i + 3] == 'b') || (gameBoardArray[i + 3] == 'c') || (gameBoardArray[i + 3] == 'd') || (gameBoardArray[i + 3] == 'f'))
			&& ((gameBoardArray[i + 6] == 'a') || (gameBoardArray[i + 6] == 'e') || (gameBoardArray[i + 6] == 'i') || (gameBoardArray[i + 6] == 'o') || (gameBoardArray[i + 6] == 'b') || (gameBoardArray[i + 6] == 'c') || (gameBoardArray[i + 6] == 'd') || (gameBoardArray[i + 6] == 'f'))
			&& ((gameBoardArray[i + 9] == 'a') || (gameBoardArray[i + 9] == 'e') || (gameBoardArray[i + 9] == 'i') || (gameBoardArray[i + 9] == 'o') || (gameBoardArray[i + 9] == 'b') || (gameBoardArray[i + 9] == 'c') || (gameBoardArray[i + 9] == 'd') || (gameBoardArray[i + 9] == 'f'))
			&& ((gameBoardArray[i + 12] == 'a') || (gameBoardArray[i + 12] == 'e') || (gameBoardArray[i + 12] == 'i') || (gameBoardArray[i + 12] == 'o') || (gameBoardArray[i + 15] == 'b') || (gameBoardArray[i + 12] == 'c') || (gameBoardArray[i + 12] == 'd') || (gameBoardArray[i + 12] == 'f'))) {
			return TRUE;
		}
		//check vowels
		if (((gameBoardArray[i + 3] == 'A') || (gameBoardArray[i + 3] == 'E') || (gameBoardArray[i + 3] == 'I') || (gameBoardArray[i + 3] == 'O') || (gameBoardArray[i + 3] == 'a') || (gameBoardArray[i + 3] == 'e') || (gameBoardArray[i + 3] == 'i') || (gameBoardArray[i + 3] == 'o'))
			&& ((gameBoardArray[i + 6] == 'A') || (gameBoardArray[i + 6] == 'E') || (gameBoardArray[i + 6] == 'I') || (gameBoardArray[i + 6] == 'O') || (gameBoardArray[i + 6] == 'a') || (gameBoardArray[i + 6] == 'e') || (gameBoardArray[i + 6] == 'i') || (gameBoardArray[i + 6] == 'o'))
			&& ((gameBoardArray[i + 9] == 'A') || (gameBoardArray[i + 9] == 'E') || (gameBoardArray[i + 9] == 'I') || (gameBoardArray[i + 9] == 'O') || (gameBoardArray[i + 9] == 'a') || (gameBoardArray[i + 9] == 'e') || (gameBoardArray[i + 9] == 'i') || (gameBoardArray[i + 9] == 'o'))
			&& ((gameBoardArray[i + 12] == 'A') || (gameBoardArray[i + 12] == 'E') || (gameBoardArray[i + 12] == 'I') || (gameBoardArray[i + 12] == 'O') || (gameBoardArray[i + 15] == 'a') || (gameBoardArray[i + 12] == 'e') || (gameBoardArray[i + 12] == 'i') || (gameBoardArray[i + 12] == 'o'))) {
			return TRUE;
		}

		//check consonants
		if (((gameBoardArray[i + 3] == 'B') || (gameBoardArray[i + 3] == 'C') || (gameBoardArray[i + 3] == 'D') || (gameBoardArray[i + 3] == 'F') || (gameBoardArray[i + 3] == 'b') || (gameBoardArray[i + 3] == 'c') || (gameBoardArray[i + 3] == 'd') || (gameBoardArray[i + 3] == 'f'))
			&& ((gameBoardArray[i + 6] == 'B') || (gameBoardArray[i + 6] == 'C') || (gameBoardArray[i + 6] == 'D') || (gameBoardArray[i + 6] == 'F') || (gameBoardArray[i + 6] == 'b') || (gameBoardArray[i + 6] == 'c') || (gameBoardArray[i + 6] == 'd') || (gameBoardArray[i + 6] == 'f'))
			&& ((gameBoardArray[i + 9] == 'B') || (gameBoardArray[i + 9] == 'C') || (gameBoardArray[i + 9] == 'D') || (gameBoardArray[i + 9] == 'F') || (gameBoardArray[i + 9] == 'b') || (gameBoardArray[i + 9] == 'c') || (gameBoardArray[i + 9] == 'd') || (gameBoardArray[i + 9] == 'f'))
			&& ((gameBoardArray[i + 12] == 'B') || (gameBoardArray[i + 12] == 'C') || (gameBoardArray[i + 12] == 'D') || (gameBoardArray[i + 12] == 'F') || (gameBoardArray[i + 15] == 'b') || (gameBoardArray[i + 12] == 'c') || (gameBoardArray[i + 12] == 'd') || (gameBoardArray[i + 12] == 'f'))) {
			return TRUE;
		}
	}
	return FALSE;
}

//Function that will check for all TRUE and FALSE values in all the different winning functions
int LevelWinnings(char gameBoardArray[16], int level) {

	if (CheckRowWinnings(gameBoardArray) == TRUE) {
		return TRUE;
	}


	if (CheckColumnsWinnings(gameBoardArray) == TRUE) {
		return TRUE;
	}

	if (CheckFirstDiagonal(gameBoardArray) == TRUE) {
		return TRUE;
	}

	if (CheckSecondDiagonal(gameBoardArray) == TRUE) {
		return TRUE;

	}

	if (level == 2) {
		if (LevelWinnings2(gameBoardArray) == TRUE) {
			return TRUE;
		}

	}


	return FALSE;

}

//Function to allow the user to input a letter and number
int response(int &number, char &letter, int &level) {
	cin >> letter;
	//If user enters 'x' the program will end
	if (letter == 'x') {
		cout << " Thanks for playing!\n";
		exit(0);
	}
	//If user enters 's' the program will prompt the user to change levels
	if (letter == 's') {

		cout << "What level of play would you like? 1: Normal, 2: Add corners & groups ";
		cin >> level;
		cout << "Level set to: " << level << endl;

		return TRUE;

	}
	else {
		//if user doesnt chose 'x' or 's' then find the user's number
		cin >> number;
	}

	return FALSE;
}

int main() {

	//Declaring variables
	char info;
	char board;
	char letter;

	//Setting number to 0
	int number = 0;
	//Setting move count to 1
	int count = 1;
	//Setting level to 1
	int level = 1;

	//Declaring 2D array to print out the table to numbers
	int NumberArray[4][4] = { { 1,2,3,4 } ,{ 5,6,7,8 } ,{ 9,10,11,12 } ,{ 13,14,15,16 } };

	//Declaring 1D array to print out the blank board
	char gameBoardArray[16] = { '.', '.', '.', '.', '.', '.', '.','.', '.', '.','.', '.', '.','.', '.', '.' };

	//Declaring 1D array for the pieces
	char gameBoardPieces[16] = { 'A', 'E', 'I', 'O', 'B', 'C', 'D', 'F', 'a', 'e', 'i', 'o', 'b', 'c', 'd', 'f' };


	//Calling PrintInfo function
	PrintInfo();
	//Calling PrintGameAndInstructions Function
	PrintGameAndInstructions();
	//Calling the printGameBoard function
	printGameBoard();

	//Creating loop to loop through all the pieces. NOTE: for loop will never reach 16 because atleast one win will occuer
	for (int i = 1; i < 16; i++) {
		//Creating while loop to loop through each user's response, in this case the first move: Player 2 enter piece, and Player 1 enter destination:";
		while (1) {
			if (W == 1) {
				break;
			}
			//Asking the user to input
			cout << count << "." << " Player 2 enter piece, and Player 1 enter destination:";

			//Sending the user's input to the response function
			int resp = response(number, letter, level);

			//Checking the value of Response
			if (resp == TRUE) {
				//Checking the value of LevelWinnings
				if (LevelWinnings(gameBoardArray, level) == TRUE) {

					//if the user likes to change the level this will check for pre-existing wins. If such a win is there, it will prompt the user an error message and reset to level 1
					cout << "Sorry, changing level would lead to a pre-existing win. Resetting the level to level 1.\n";
					level = 1;

					//Printing out the board and pieces
					ChangesBoard(NumberArray, gameBoardArray, gameBoardPieces);
					gameBoardPiecesChange(letter, number, gameBoardArray, gameBoardPieces);
					continue;
				}
				//Printing out the board and pieces
				ChangesBoard(NumberArray, gameBoardArray, gameBoardPieces);
				gameBoardPiecesChange(letter, number, gameBoardArray, gameBoardPieces);
				continue;

			}

			//setting variable input to the userInput function
			int input;
			input = UserInput(letter, number, NumberArray, gameBoardArray, gameBoardPieces);
			//Setting variable to LevelWinnings function
			int winning = LevelWinnings(gameBoardArray, level);

			//Checking the value of Input
			if (input == FALSE) {

				//Prompt error message if the user's chosen piece is invalid or the place is already taken
				cout << "Sorry that place or piece is already taken! Please try again\n";

				//Printing out the board and the pieces
				ChangesBoard(NumberArray, gameBoardArray, gameBoardPieces);
				gameBoardPiecesChange(letter, number, gameBoardArray, gameBoardPieces);

				//Checking if Winning is TRUE
				if (winning == TRUE) {
					//If player wins prompt this message and exit the game
					cout << "Player 1 Wins!\n";
					cout << "Thanks for playing!\n";
					W = 1;
					//exit(0);
				}
			}

			else {
				//Print out the gameboard and pieces
				ChangesBoard(NumberArray, gameBoardArray, gameBoardPieces);
				gameBoardPiecesChange(letter, number, gameBoardArray, gameBoardPieces);

				//Checking if Winning is TRUE
				if (winning == TRUE) {
					//If players win prompt this message and exit the game
					cout << "Player 1 Wins!\n";
					cout << "Thanks for playing!\n";
					W = 1;
					//exit(0);
				}
				break;
			}


		}
		//Increment Counter
		count++;

		//Creating while loop to loop through each user's response, in this case the first move: Player 1 enter piece, and Player 2 enter destination:";
		while (1) {
			if (W == 1) {
				break;
			}
			//Asking the user for input
			cout << count << "." << " Player 1 enter piece, and Player 2 enter destination:";

			//Sending user input to response function
			int resp = response(number, letter, level);

			//Checking the value of Response
			if (resp == TRUE) {
				//Checking the value of Level Winnings
				if (LevelWinnings(gameBoardArray, level) == TRUE) {
					//If the user would like to change the level, this will check for a pre-existing win. If such a win is there it will prompt this error message and the reset the level to 1
					cout << "Sorry, changing level would lead to a pre-existing win. Resetting the level to level 1.\n";
					level = 1;

					//Printing out the board and pieces
					ChangesBoard(NumberArray, gameBoardArray, gameBoardPieces);
					gameBoardPiecesChange(letter, number, gameBoardArray, gameBoardPieces);
					continue;
				}
				//Printing out the board and the pieces
				ChangesBoard(NumberArray, gameBoardArray, gameBoardPieces);
				gameBoardPiecesChange(letter, number, gameBoardArray, gameBoardPieces);
				continue;
			}

			//Setting variable equal to the UserInput function
			int input;
			input = UserInput(letter, number, NumberArray, gameBoardArray, gameBoardPieces);
			//Setting variable equal to the LevelWinnings function
			int winning = LevelWinnings(gameBoardArray, level);

			//Checking the value of the input
			if (input == FALSE) {

				//Prompt error message if the user selected an invalid piece or a place that is taken
				cout << "Sorry that place or piece is already taken! Please try again\n";

				//Prints out gameboard and pieces
				ChangesBoard(NumberArray, gameBoardArray, gameBoardPieces);
				gameBoardPiecesChange(letter, number, gameBoardArray, gameBoardPieces);

				//Checking if Winning is TRUE
				if (winning == TRUE) {

					//If a win is there, prompt this message and exit game
					cout << "Player 2 Wins!\n";
					cout << "Thanks for playing!\n";
					W = 1;
					//exit(0);
				}
				break;
			}
			else {

				//Printing gameboard and pieces
				ChangesBoard(NumberArray, gameBoardArray, gameBoardPieces);
				gameBoardPiecesChange(letter, number, gameBoardArray, gameBoardPieces);

				//Checking if the Value of Winning is TRUE
				if (winning == TRUE) {
					//If a win is found, prompt the message and exit game
					cout << "Player 2 Wins!\n";
					cout << "Thanks for playing!\n";
					W = 1;
					//exit(0);
				}
				break;

			}
		}

		//incrementing Count
		count++;

	}

	//Return 0
	return 0;
}//End of Program 4 DoubleDown
