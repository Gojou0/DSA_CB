#include<iostream>
#include<vector>
using namespace std;

bool safehai(vector<vector<char> > &board, int i, int j){
    int oi = i, oj = j;
    // Left diagonal
    while (i >= 0 && j >= 0){
        if (board[i][j] == 'Q') return false;
        i--;
        j--;
    }

    // Right diagonal
    i = oi , j = oj;
    while (i >= 0 && j < board[i].size()){
        if (board[i][j] == 'Q') return false;
        i--;
        j++;
    }

    // Column
    i = oi, j = oj;
    while (i >= 0){
        if (board[i][j] == 'Q') return false;
        i--;
    }

    return true;
}

bool Nqueen(vector<vector<char> > &board, int index = 0){
    if (index == board.size()){
        for(int i = 0 ; i < board.size(); i++){
            for (int j = 0; j < board[0].size(); j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return false;
    }

    for (int j = 0; j < board[index].size(); j++){
        if (safehai(board, index, j)){
            board[index][j] = 'Q';
            bool x = Nqueen(board, index+1);
            if (x) return true;
            board[index][j] = '_';    // backtracking
        }
    }

    return false;
}

int main(){
    int queens;
    cin >> queens;
    vector<vector<char> > board(queens, vector<char> (queens, '_'));
    Nqueen(board);

}