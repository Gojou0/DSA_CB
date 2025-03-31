#include <iostream>
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

    int top = 0;
    int left = 0;
    int bottom = n - 1;
    int right = m - 1;
    while (left <= right && top <= bottom){
        for (int i = top; i <= bottom; i++){
            cout << a[i][left] << ", ";
        }
        left++;

        for (int i = left; i <= right; i++){
            cout << a[bottom][i] << ", ";
        }
        bottom--;

        if (left <= right){
            for (int i = bottom; i >= top; i--){
                cout << a[i][right] << ", ";
            }
            right--;
        }

        if (top <= bottom){
            for (int i = right; i >= left; i--){
                cout << a[top][i] << ", ";
            }
            top++;
        }
    }
    cout << "END" << endl;
}