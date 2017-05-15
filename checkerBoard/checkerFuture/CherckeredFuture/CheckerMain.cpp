//********************************************************************
// CheckerMain.cpp 
//    Author:    Joel Fernandes
//    Date:      September 14, 2016
//    Class:     CIS 200, Prof. Bruce Elenbogen
//    Purpose:   This program helps find and picks out the maximum nymber of
//               jumps on a 8x8 board.
//    Input:     User is asked how many peice for P1 (player1) & P2 (Player2)
//    Output:    Depend on how many piece on P2, P1 can make the best jump
//    Known bug:  
//********************************************************************
# include <iostream>
using namespace std;


class Board
{
	public:
       Board();                                                             //creates an empty board
       void reset();                                                        //clears the board
       void addChecker(char who, int row, int col);
	   int numJumps(int row, int col);                                      // num of jumps possible from row, col
       void print();                                                        // print the board for debugging only
       void NumberOfJumps();                                                // show number of jumps


private:
	char board[8][8];

};

int main()
{

   
    int TestCases;                                                          // Number of testcase input
    int P1 = 0;                                                             // Player 1 P1 is represented by X
    int P2 = 0;                                                             // Player 2 P2 is represented by $
    int row;
    int col;



    Board board2;
    cin >> TestCases;


    for (int a = TestCases; TestCases > 0; TestCases--){

            cin >> P1;                                                      // P1 is represented by X
            cin >> P2;                                                      // P2 is represented by $

            board2.reset();                                                 //clears the board

        for (int b = 0; P1 > b; P1--){
            cin >> row >> col;
            board2.addChecker('X', row, col);
        }
        for (int c = 0; P2 > c; P2--) {
            cin >> row >> col;
            board2.addChecker('$', row, col);
        }
       board2.NumberOfJumps();                                             // show the jumps to the user
    }
    return 0;

}

Board::Board(){
/*  name : Board::Board
    purpose: Creates an empty board
    pre : none
    post :   Creates an empty board
    calls
    by: main
    calls: none
*/

    reset();

}

int maxJumps(int leftUpper, int leftBottom, int rightUpper, int rightBottom){
/*  name : maxJumps
    purpose: Recursion to find the Maximun of jump in leftUpper, LeftBottom,
             rightUpper and rightbottom
    pre : Jumps set as zero and jump in different direction.
    post : return Maximum jumps out of 4 
    calls
    by: numJumps
    calls: none
*/

    int Jumps = 0;

    if (leftUpper > Jumps){
        Jumps = leftUpper;
    }
    if (leftBottom > Jumps){
        Jumps = leftBottom;
    }
    if (rightUpper > Jumps){
        Jumps = rightUpper;
    }
    if (rightBottom > Jumps){
        Jumps = rightBottom;
    }

    return Jumps;

}


int Board::numJumps(int row, int col){
 /* name : Board::numJumps 
    purpose: Recursion to find the Maximun of jump in leftUpper, LeftBottom,
    rightUpper and rightbottom
    pre : Find the number of possible jumps over P2 '$'
    post : Check and find number of jump in the direction around P2
    calls
    by: NumberOfJumps
    calls: maxJumps
*/

    int LeftUpper = 0;
    int LeftBottom = 0;
    int RightUpper = 0;
    int RightBottom = 0;

    if (board[row][col] == 'X') {
                                                                            // Jump left upper 
        if (row >= 2 && col >= 2 && board[row - 1][col + 1] == '$' && board[row - 2][col + 2] == ' ') {   
            
            board[row - 1][col + 1] = ' ';                                  //Save the jump information
            board[row][col] = ' ';
            board[row - 2][col + 2] = 'X';
            LeftUpper = 1 + numJumps(row - 2, col + 2);
        }
                                                                            // Jump left bottom
        if (row <= 5 && col >= 2 && board[row - 1][col - 1] == '$' && board[row - 2][col - 2] == ' ') { 
            board[row - 1][col - 1] = ' ';                                  //Save the jump information
            board[row][col] = ' ';
            board[row - 2][col - 2] = 'X';
            LeftBottom = 1 + numJumps(row - 2, col - 2);
        }
                                                                            // Jump Right upper
        if (row >= 2 && col <= 5 && board[row + 1][col + 1] == '$' && board[row + 2][col + 2] == ' ') {
            board[row + 1][col + 1] = ' ';                                  //Save the jump information
            board[row][col] = ' ';
            board[row + 2][col + 2] = 'X';
            RightUpper = 1 + numJumps(row + 2, col + 2);
        }
                                                                            // Jump Right bottom
        if (row <= 5 && col <= 5 && board[row + 1][col - 1] == '$' && board[row + 2][col - 2] == ' ') {
            board[row + 1][col - 1] = ' ';                                  //Save the jump information
            board[row][col] = ' ';
            board[row + 2][col - 2] = 'X';
            RightBottom = 1 + numJumps(row + 2, col - 2);
        }


        return maxJumps(LeftUpper, LeftBottom, RightUpper, RightBottom);
    }
    else
    return 0;
}

void Board::NumberOfJumps(){
/*  name : Board::NumberOfJumps 
    purpose: Recursion to find the Maximun of jump in leftUpper, LeftBottom,
    rightUpper and rightbottom
    pre : Find the number of possible jumps from numJumps(i, j)
    post : print the "the number of jumps is " over the P2 piece
    calls
    by: NumberOfJumps
    calls: maxJumps
*/

    int NumberJumps;
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
      if (board[i][j] == 'X'){
            NumberJumps = numJumps(i, j);
            cout << "the number of jumps is " << NumberJumps << endl;

      }
    }
  }
}


void Board::print(){
/*  name : Board::print
    purpose: Shows outside the 8 x 8 board
    pre : board contains printable characters post : the board is displayed
    post : Display the board 
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

void Board::addChecker(char who, int row, int col){
/*  name : Board::addChecker
    purpose: Prompt the user char "who" to move P1 or P2 pieces
    pre : 'who' is character given in the main.
    post : board[7 - row][ col] = who;
    calls
    by: main
    calls: Board::board & Board::print (for debug purpose)
*/
//   Board board1; // enable this for print the board
 
    board[8 - row][ col] = who;
//    board1.print();  //  print board here for Debugging


}



void Board::reset(){
/*  name : Board::reset
    purpose: create an empty board
    pre : none
    post : board[i][j] = ' ' for all i rows and j columns
    calls
    by: main
    calls: none
*/

//  print this board here for Debugging and comment the other board
/*
   printf("+---+---+---+---+---+---+\n");
    cout << " ";
    for (int i = 0; i < 8; i++)

        cout << ' ' << i << ' ';

    for (int i = 0; i < 8; i++) {
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
*/
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++)
            board[i][j] = ' ';
    }

}





