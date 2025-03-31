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
    int key;
    cin >> key;

    int s = 0;
    int e = m - 1;
    int ans = 0;
    while (s < n && e >= 0){
        if (a[s][e] == key) {
            ans = 1;
            break;
        }
        else if (a[s][e] < key) s++;
        else e--;
    }
    cout << ans << endl;
}