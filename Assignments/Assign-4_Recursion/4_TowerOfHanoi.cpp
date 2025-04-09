#include<iostream>
using namespace std;

void TOI(int n, char src, char helper, char des){
    if (n == 0) return;

    TOI(n-1, src, des, helper);
    cout << "Moving ring " << n << " from " << src << " to " << des << endl;
    TOI(n-1, helper, src, des);
}

int main(){
    int n;
    cin >> n;

    TOI(n, 'A', 'C', 'B');
}