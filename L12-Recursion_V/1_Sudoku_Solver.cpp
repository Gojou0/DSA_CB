#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

bool safehai(vector<vector<int> > &board, int i, int j, int n){
    for (int k = 0; k < board.size(); k++){
        if (board[i][k] == n) return false;
        if (board[k][j] == n) return false;
    }

    int si = (i / sqrt(board.size())) * sqrt(board.size());             // find the starting coordinates of block
    int sj = (j / sqrt(board.size())) * sqrt(board.size());
    for (int x = si; x < si + sqrt(board.size()); x++){
        for (int y = sj; y < sj + sqrt(board.size()); y++){
            if (board[x][y] == n) return false;
        }
    }
    return true;
}

bool Solve(vector<vector<int> > &board, int i = 0, int j = 0){
    if (i == board.size()){
        for (int a = 0; a < board.size(); a++){
            for (int b = 0; b < board.size(); b++){
                cout << board[a][b] << " ";
            }
            cout << endl;
        }
        return true;
    }

    if (j == board.size()){                                 // if a row completed go to next row
        return Solve(board, i+1, 0);
    }

    if (board[i][j]){                               // if a cell is already filled then skip it
        return Solve(board, i, j+1);
    }

    for (int n = 1; n <= board.size(); n++){                // fill first cell  and other by recursion
        if (safehai(board, i, j, n)){
            board[i][j] = n;
            bool canSolve = Solve(board, i, j+1);
            if (canSolve) return true;
            board[i][j] = 0;
        }
    }
    return false;
}

int main(){
    vector<vector<int> > board(9, vector<int>(9,0));
    int row0[] = {5, 3, 0, 0, 7, 0, 0, 0, 0};
    int row1[] = {6, 0, 0, 1, 9, 5, 0, 0, 0};
    int row2[] = {0, 9, 8, 0, 0, 0, 0, 6, 0};
    int row3[] = {8, 0, 0, 0, 6, 0, 0, 0, 3};
    int row4[] = {4, 0, 0, 8, 0, 3, 0, 0, 1};
    int row5[] = {7, 0, 0, 0, 2, 0, 0, 0, 6};
    int row6[] = {0, 6, 0, 0, 0, 0, 2, 8, 0};
    int row7[] = {0, 0, 0, 4, 1, 9, 0, 0, 5};
    int row8[] = {0, 0, 0, 0, 8, 0, 0, 7, 9};

    for (int i = 0; i < 9; i++) board[0][i] = row0[i];
    for (int i = 0; i < 9; i++) board[1][i] = row1[i];
    for (int i = 0; i < 9; i++) board[2][i] = row2[i];
    for (int i = 0; i < 9; i++) board[3][i] = row3[i];
    for (int i = 0; i < 9; i++) board[4][i] = row4[i];
    for (int i = 0; i < 9; i++) board[5][i] = row5[i];
    for (int i = 0; i < 9; i++) board[6][i] = row6[i];
    for (int i = 0; i < 9; i++) board[7][i] = row7[i];
    for (int i = 0; i < 9; i++) board[8][i] = row8[i];

    if (!Solve(board)){
        cout << "NO SOL" << endl;
    }
}