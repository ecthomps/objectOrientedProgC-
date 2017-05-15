/*
//********************************************************************
// friends.cc 
//     Author:   Joel Fernandes
//     Date:     September 14, 2016
//     Class:    CIS 200, Prof. Bruce Elenbogen
//     Purpose:  This program picks the best move to jump in the checkerboard
//     Input:    2 
//               1 1
//               3 3
//               4 4
//     Output:   the number of jumps is 1
//********************************************************************
# include <iostream>
using namespace std;


class Board
{
	public:
	   Board(); //creates an empty board
       void reset(); //clears the board
	   void addChecker(char who, int row, int col);
	   int numJumps(int row, int col); // num of jumps possible from row, col
	   void print(); // print the board for debugging only
private:
	char board[8][8];

};


	
void addChecker(char who, int row, int col)
{
	
}

void print()
{
	
}

int main()
{
	int TestCases;
	cout << "" ; /// Enter number of test cases
	cin >> TestCases;




}

*/
