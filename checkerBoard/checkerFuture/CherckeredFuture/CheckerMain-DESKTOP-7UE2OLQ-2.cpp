//********************************************************************
// CheckerMain.cpp 
//    Author:    Joel Fernandes
//    Date:      September 14, 2016
//    Class:     CIS 200, Prof. Bruce Elenbogen
//    Purpose:   This program picks the best move to jump in the checkerboard
//    Input:     User is asked how many peice for P1 (player1) & P2 (Player2)
//    Output:    Depend on how many piece on P2, P1 can make the best jump
//    Known bug:  
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

int main()
{

   
    int TestCases; // Number of testcase input
    int P1 = 0; // Player 1
    int P2 = 0; // Player 2
    int row;
    int col;
    int row2;
    int col2;
    char p1 = 'X';
    char p2 = '$';

    Board board2;
    cout << "##### CHECKER GAME ##### \n";
    cout << " "; /// Enter number of test cases
    cin >> TestCases;  //Create a for loop to check whether the testCase has not been exceeded 
                        // Inside the for loop add the players P1 and P2.

    cout << "" << endl; // how many pieces for player 1 (P1) & player 2 (P2)
    cin >> P1; // P1 is represented by X // For loop for P1 and check of position include add checker
    cin >> P2; // P2 is represented by $ // For loop for P2 and check of position include add checker
    
    cin >> row >> col;

    cin >> row2 >> col2;
    board2.addChecker(p1, row, col);
    board2.addChecker( p2, row2, col2);


    return 0;

}

Board::Board(){
/*  name : Board::Board
    purpose: Shows the 8 x 8 board with _
    _ mean no check peice on the board
    pre : board contains printable characters post : the board is displayed
    calls
    by: main
    calls: none
*/
    int i, j;
    for (i = 0; i < 8; i++) {// Show row 'i'
        for (j = 0; j < 8; j++){ // Show column 'j'
            board[i][j] = '_';


        }
    }
}


void Board::print(){
/*  name : Board::print
    purpose: Shows outside the 8 x 8 board
    pre : board contains printable characters post : the board is displayed
    calls
    by: main
    calls: none
*/
    printf("+---+---+---+---+---+---+\n");
    cout << " ";
    for (int i = 0; i < 8; i++)

        cout << ' ' << i << ' ';

    for (int i = 0; i < 8; i++)
    {
        cout << endl;
        cout << i << " ";
        for (int j = 0; j < 8; j++)
            if (board[i][j] == '  ')
                cout << "  ";
            else
                cout << ' ' << board[i][j] << ' ';
        cout << endl;
    }
    printf("+---+---+---+---+---+---+\n");


}

void Board::addChecker(char who, int row, int col)
{
/*  name : Board::addChecker
    purpose: Prompt the user char "who" to move P1 or P2 pieces
    pre : 'who' is character given in the main.
    calls
    by: main
    calls: Board::board & Board::print
*/
    Board board1;
 
    board[row][col] = who;
    board1.print();


}




