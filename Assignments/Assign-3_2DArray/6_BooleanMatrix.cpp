#include<iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    int col0 = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (a[i][j] == 1){
                a[i][0] = 1;
                if (j == 0){
                    col0 = 1;
                }else{
                    a[0][j] = 1;
                }
            }
        }
    }

    for (int i = 1; i < n; i++){
        for (int j = 1; j < m; j++){
            if (a[i][j] == 0){
                if (a[i][0] == 1 || a[0][j] == 1){
                    a[i][j] = 1;
                }
            }
        }
    }

    if (a[0][0] == 1){
        for (int j = 0; j < m; j++) a[0][j] = 1;
    }
    if (col0 == 1){
        for (int i = 0 ; i < n; i++) a[i][0] = 1;
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}