#include <iostream>
using namespace std;
 int main(){
    int a[5] = {1};
    int n = sizeof(a)/sizeof(int);

    for (int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
 }