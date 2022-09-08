#include <iostream>

#include <vector>

using namespace std;

bool CheckisValid(vector < vector < char >> & board, int row, int column, char value) {
  for (int iterator = 0; iterator < 9; iterator++) {
    if (board[iterator][column] == value)
      return false;

    if (board[row][iterator] == value)
      return false;

    if (board[3 * (row / 3) + iterator / 3][3 * (column / 3) + iterator % 3] == value)
      return false;
  }
  return true;
}

bool SudokuSolver(vector < vector < char >> & board) {
  for (int row = 0; row < board.size(); row++) {
    for (int column = 0; column < board[0].size(); column++) {
      if (board[row][column] == '.') {
        for (char character = '1'; character <= '9'; character++) {
          if (CheckisValid(board, row, column, character)) {
            board[row][column] = character;

            if (SudokuSolver(board))
              return true;
            else
              board[row][column] = '.';
          }
        }

        return false;
      }
    }
  }
  return true;
}
int main() {
    cout<<"Enter the values in sudoku puzzle"<<endl;
    vector<vector<char>>board(9,vector<char>(9));
    for (int i = 0; i < 9; i++)
    {
        cout<<"Enter the values of the "<<i<<" row"<<endl;
        for(int j=0;j<9;j++)
        {
            cin>>board[i][j];
        }
    }
    
   
    SudokuSolver(board);
    cout<<"The final sudoku is :"<<endl;    	
    for(int i= 0; i< 9; i++){
        for(int j= 0; j< 9; j++)
            cout<<board[i][j]<<" ";
            cout<<"\n";
    }
    return 0;
}