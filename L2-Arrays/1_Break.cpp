#include <iostream>
using namespace std;
 
int main(){

    int a[] = {1,2,3,4,5};
    int n = sizeof(a) / sizeof(int);

    int key = 41;
    int i;
    
    for (i = 0; i < n; i++){
        if( a[i] == key) {
            cout<< i;
            break;
        }
    }
    if (i == n) cout<<"notfound";

    return 0;
}