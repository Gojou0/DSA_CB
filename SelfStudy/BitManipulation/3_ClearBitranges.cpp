#include<iostream>
#include<math.h>
using namespace std;

int ClearRange(int n, int i){
    int mask = (~0);
    mask = mask << i;
    return (n & mask);
}

void clearjtoi(int &n, int j, int i){                    // clearing from j to i-1
    int ma = ~0;
    ma = ma << j;
    int mb = pow(2, i) - 1;
    int mask = ma | mb;
    n = n & mask;
}

int main(){
    int n, i;
    cin >> n;
    // cin >> n >> i;
    // cout << ClearRange(n, i) << endl;
    clearjtoi(n, 4, 2);
    cout << n << endl;
}