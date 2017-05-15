/*
Name: Eranus Christian Thompson
Date: 09-22-2016
Class: CIS 200-02

Description: This program aims to design a checker board using a two dimensional
			 array with 8 rows and 8 col. The game is played betweeen two players
			 with player 1 assumed to be a king. The players move in a straight diagonal
			 line. The king can make a legal jump over it's opponent's piece (player 2) in a 
			 if only the landing square is not occupied. If the landing square is occupied then 
			 the jump move is illegal. The king can only capture one piece and remove that piece 
			 from the board in a single jump, but not limted to make multiple jumps in a single turn.
			 The program uses recursion and classes to determine number of test cases for possible jumps 
			 and to return the maximum number of jumps possible of one specific king checker in a turn.
*/

#include <iostream>
#include <string>
#include <algorithm>

const int MAX_ROW = 8, MAX_COL = 8;
using namespace std;

class BoardType {

public:
	BoardType();									    //creates an empty board       
	void reset();									   //clears the board       
	void addChecker(char who, int row, int col);	  //adds players pieces to the board
	void delChecker(int row, int col);				 //deletes players pieces after a jump move
	int numJumps(int row, int col);					// num of jumps possible from row, col       
	void print();								   // print the board for debugging only

private:
	char board[MAX_ROW][MAX_COL];	//board used to play
};


int main() {

	BoardType checker;
	int numJumps;	

	char p1 = '*';						   //player1 symbol
	char p2 = '.';						  //player2 symbol

	int numCase, p1Row, p1Col, p2Row, p2Col;
	int kingRow, kingCol;
	int p1Checker, p2Checker;

	cin >> numCase;						   //reads in the number of cases

	for (int x = 0; x < numCase; x++){

		cin >> p1Checker >> p2Checker;		 //reads in the muber of pieces for both player 1 and 2

	for(int i = 0; i < p1Checker; i++){ //reads in the rows and columns for player 1

		cin >> p1Row >> p1Col;
	if (i <= 0) {			//assigns the first row and column of player 1 to king row and column
		kingRow = p1Row;
		kingCol = p1Col;
	}
		checker.addChecker(p1, p1Row, p1Col); 
	}

	for(int i = 0; i < p2Checker; i++){ //reads in the rows and columns for player 2

		cin >> p2Row >> p2Col;
		checker.addChecker(p2, p2Row, p2Col);
	}	
	
		numJumps = checker.numJumps(kingRow, kingCol);			
		cout << "the number of jumps is " << numJumps << endl; //prints out the maximum number of jumps
		checker.reset();		
	}

	return 0;
}

BoardType::BoardType()
{
	reset();
}

void BoardType::reset()
{
	/*
	name	: reset
	purpose : Sets the board to an empty board
	pre		: Function to clear the entire board
	post	: The entire board rows and column are filled
			  with an empty space character
			  board[r][c] = ' '
	*/
	for (int r = 0; r < 8; r++) {
		for (int c = 0; c < 8; c++) {

			board[r][c] = ' ';
		}
	}
}

void BoardType::addChecker(char who, int row, int col)
{
	/*
	name	: addChecker
	purpose : assigns special characters 'x' and 'o' to be used
			  to identify players checkers on the board
	pre		: Function to add player's pieces on the board
			  Depending on "who" the player is pieces are added 
			  to the board according to the row and col on the parameter 
	post	: If "who" is '*' 
			  board[row][col] = 'x'
			  else if "who" is '.'
			  board[row][col] = 'o'
	*/
	if (who == '*') {
		board[row][col] = 'x';
	}
	else if (who == '.') {
		board[row][col] = 'o';
	}
}

void BoardType::delChecker(int row, int col)
{
	/*
	name	: delChecker
	purpose : Removes a players checker from an assign row and column
	pre		: Player's pieces are removed from a specific location
			  on the board. Pieces are deleted of the board according to 
			  the parameters
	post	: board[row][col] = ' ';
	*/
	board[row][col] = ' ';

}

int BoardType::numJumps(int row, int col)
{
	/*
	name	: numJumps
	purpose	: Computes the maximum number of jumps possible for a king
			  Row and Col are first tested to determine if they are greater than 
			  or lesser than the board endRow and endCol. Then board[row][col] is checked 
			  with the first four diagonal lines(DownRight, DownLeft, UpRight, UpLeft)
			  to determine if they're not equal to a blank character and player1 (or the kings) 
			  checkers. If this three test cases are true, then board[row][col] is checked with 
			  the second (next) four diagonal lines (DownRight, DownLeft, UpRight, UpLeft) to determine
			  if they're equal to a blank. If true, then board[row][col] is assigned to that position,
			  deletes it's original position and it's opponents position. Count is then assigned to
			  maximum number oj jumps made after the recursive call to the function numJumps. The original
			  board[row][col] pieces are returned back on the board, and the function returns count
	pre		: Function to compute number of jumps possible 
			  from rows and columns. Returns the maximum number of
			  jumps
	post	: Returns the number of jumps possible
	*/
	int count = 0;

	int endRow = 7;
	int endCol = 7;
	
	//DownRight Check
	if (!(row + 2 > endRow || col + 2 > endCol) && (board[row + 1][col + 1] != ' ' 
		                                        && board[row + 1][col + 1] != 'x')) {

		if (board[row + 2][col + 2] == ' ') {

			addChecker('*', row + 2, col + 2);
			delChecker(row, col);
			delChecker(row + 1, col + 1);
						
			count = max(count, 1 + numJumps(row + 2, col + 2));			

			addChecker('*', row, col);
			addChecker('.', row + 1, col + 1);		
		}
	}

	//UpLeft Check
	if (!(row - 2  < 0 || col - 2 < 0) && (board[row - 1][col - 1] != ' '
		                               && board[row - 1][col - 1] != 'x')) {

		if (board[row - 2][col - 2] == ' ') {

			addChecker('*', row - 2, col - 2);
			delChecker(row, col);
			delChecker(row - 1, col - 1);
			
			count = max(count, 1 + numJumps(row - 2, col - 2));

			addChecker('*', row, col);
			addChecker('.', row - 1, col - 1);
		}
	}

	//DownLeft Check
	if (!(row + 2  > endRow || col - 2 < 0) && (board[row + 1][col - 1] != ' ')
		                                    && board[row + 1][col - 1] != 'x') {

		if (board[row + 2][col - 2] == ' ') {
			addChecker('*', row + 2, col - 2);
			delChecker(row, col);
			delChecker(row + 1, col - 1);
			
			count = max(count, 1 + numJumps(row + 2, col - 2));

			addChecker('*', row, col);
			addChecker('.', row + 1, col - 1);			
		}
	}

	//UpRight Check
	if (!(row - 2  < 0 || col + 2 > endCol) && (board[row - 1][col + 1] != ' '
		                                    && board[row - 1][col + 1] != 'x')) {

		if (board[row - 2][col + 2] == ' ') {
			addChecker('*', row - 2, col + 2);
			delChecker(row, col);
			delChecker(row - 1, col + 1);

			count = max(count, 1 + numJumps(row - 2, col + 2));

			addChecker('*', row, col);
			addChecker('.', row - 1, col + 1);			
		}
	}

	delChecker(row, col);
	return count;
}

void BoardType::print()
{
	/*
	name    : print
	purpose : Prints out the checker board in an 8 by 8 rows and columns
			  The vertical line character "|" is used to separate columns
			  and the horizontal line character is to separate rows "_"
	pre	    : Function to print the board. Contains printable characters
	post    : The board is printed out 
	*/
	for (int i = 0; i < 8; i++) {
		cout << '|';
		for (int j = 0; j < 8; j++) {
			if (board[i][j] == ' ') {
				cout << '_';
			}
			else {
				cout << board[i][j];
			}

			cout << '|';
		}
		cout << endl;
	}
}