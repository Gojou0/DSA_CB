#include <iostream>
using namespace std;

int main(){
    int m = 4;
    int n = 3;
    int matrix[3][4] = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    // int col[m] = {0};  -> matrix[0][...]
    // int row[n] = {0};  -> matrix[...][0]
    int col0 = 1;   // to  prevent double count of 1st cell in matrix .... use it to store first index col

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (matrix[i][j] == 0){
                // mark the ith row
                matrix[i][0] = 0;
                // mark the jth column
                if (j != 0){                // to  prevent double count of 1st cell in matrix
                    matrix[0][j] = 0;
                }else{
                    col0 = 0;
                }
                
            }
        }
    }

    // start filling zero except for first row and column
    for (int i = 1; i < n; i++){
        for (int j = 1; j < m; j++){
            if (matrix[i][j] != 0){
                // check for zero for col & row
                if (matrix[i][0] == 0 || matrix[0][j] == 0){             
                    matrix[i][j] = 0;
                }         
            }
        }
    }

    // now fill zeros for first row and column
    if (matrix[0][0] == 0){                                 // first fill first row based on first cell coz of col0 variable
        for (int j = 0; j < m; j++) matrix[0][j] = 0;
    }
    if (col0 == 0){                                          // then fill first col based col0 variable
        for (int i = 0; i < n; i++) matrix[i][0] = 0;
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}