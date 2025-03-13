#include <iostream>
using namespace std;

int main(){
    int a[] = {1,2,3,4,5};
    int n = sizeof(a) / sizeof(int);

    for (int i = 0 ; i < n; ++i){
        cout << "Subarrays with size " << i+1 << ":" << endl;
        for (int j = 0; j < n - i; j++){
            int end = j + i ;
            for (int k = j; k <= end; k++){
                cout << a[k] << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}