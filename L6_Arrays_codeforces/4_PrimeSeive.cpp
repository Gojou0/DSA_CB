#include <iostream>
using namespace std;
bool a[10000005];

// Time complexity -> root(N)log2(log2(root(N)))

int main(){
    int n; 
    cin >> n;
    for (int i = 0; i < 10000005; i++){
        a[i] = true;
    }

    for (int i = 2; i * i <= n; i++){
        if (a[i] == true){
            for (int j = i*i; j <= n; j += i){
                a[j] = false;
            }
        }
    }
    a[0] = a[1] = false;

    for (int i = 0; i <= n; i++){
        if (a[i] == true){
            cout << i << " ";
        }
    }
}