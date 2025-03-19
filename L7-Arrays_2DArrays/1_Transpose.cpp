#include <iostream>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    int a[n][m];
    int n0 = 1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            a[i][j] = n0++;
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++){
        for (int j = i; j < m; j++){
            swap(a[i][j], a[j][i]);
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}