#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n][n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    int ans = INT_MIN;
    int ansj;
    for (int j = 0; j < n; j++){
        int sum = 0;
        for (int i = 0; i < n; i++){
            sum += a[i][j];
        }
        if (sum > ans){
            ans = sum;
            ansj = j + 1;
        }
    }

    cout << ansj << " " << ans << endl;
}