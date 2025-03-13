#include <iostream>
using namespace std;

int main(){
    int a[] = {7,5,7,5,7,5,5,5,4,7,6,7,5,5,5};
    int n = sizeof(a) / sizeof(int);

    int element;     // to store element having count not cancelled
    int cancel = 0;     // to store count which can be cancelled

    // loop to check which element counts doesn't gets cancelled (MOORE VOTING ALGO)
    for (int i = 0; i < n; i++){
        if (cancel == 0){
            element = a[i];
        }
        if (a[i] == element){
            cancel++;
        }else{
            cancel--;
        }
    }

    // loop to verify the element to be answer
    int c = 0;
    for (int i = 0; i < n; i++){
        if (a[i] == element){
            c++;
        }
    }
    if (c > n / 2){
        cout << element << endl;
    }
}