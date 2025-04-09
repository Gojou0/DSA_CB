#include<iostream>
using namespace std;

void Odd(int n){
    if (n <= 0) return;

    if (n % 2 != 0){
        cout << n << endl;
        Odd(n-2);
    }else{
        cout << n-1 << endl;
        Odd(n-2);
    }
}

void Even(int n){
    if (n <= 1) return;

    if (n % 2 == 0){
        Even(n-2);
        cout << n << endl;
    }else{
        Even(n-2);
        cout << n-1 << endl;
    }
}

void OddEven(int n){
    if (n < 1) return;

    if (n % 2 != 0) cout << n << endl;

    OddEven(n-1);

    if (n % 2 == 0) cout << n << endl;
}

int main(){
    int n;
    cin >> n;

    // Odd(n);
    // Even(n);
    OddEven(n);
}