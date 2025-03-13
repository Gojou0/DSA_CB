#include <iostream>
using namespace std;

int main(){
    int a[] = {3,4,-2,5,8,20,-10,8};
    int n = sizeof(a) / sizeof(int);
    int ps[100] = {0};
    int key;

    ps[0] = a[0];
    for (int  i = 1; i < n; ++i){
        ps[i] = ps [i-1] + a[i];
    }

    for (int i = 0; i < n; ++i){
        if(ps[i] == ps[n-1] - ps[i]){
            key = i;
        }
    }

    cout << "Subarray 1 : ";
    for (int i = 0; i <= key; i++){
        cout << a[i] << " ";
    }
    cout << endl;

    cout << "Subarray 2 : ";
    for (int i = key+1; i < n; i++){
        cout << a[i] << " ";
    }

    return 0;
}