#include <iostream>
using namespace std;
int main() {
    int n; 
    cin >> n;
    int a[n] = {0};
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int ps = 0;
    for (int i = 0; i < n; i++){
        ps += a[i];
        cout << ps << " ";
    }
}