#include<iostream>
using namespace std;

int main(){
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    char a[n][m];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (a[i][j] == '#') break;
            else if (a[i][j] == '.'){
                if (j == m-1) s -= 2;
                else s -= 3;
            }
            else{
                if (j == m-1) s += 5;
                else s += 4;
            }
        }
        if (s >= k) continue;
        else break;
    }
    if (s >= k){
        cout << "Yes" << endl;
        cout << s << endl;
    }else{
        cout << "No" << endl;
    }

}