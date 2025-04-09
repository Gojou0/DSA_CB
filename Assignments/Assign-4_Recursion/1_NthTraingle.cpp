#include<iostream>
using namespace std;

int Ntriangle(int n){
    if (n == 0) return 0;

    return n + Ntriangle(n-1);
}

int main(){
    int n;
    cin>> n;

    cout << Ntriangle(n) << endl;
}