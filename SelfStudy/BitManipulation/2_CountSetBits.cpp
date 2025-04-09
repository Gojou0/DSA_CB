#include<iostream>
using namespace std;

int CountBits(int n){
    int ans = 0;
    while (n > 0){
        if ((n & 1) == 1){
            ans++;
        }
        n = (n >> 1);
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    cout << CountBits(n) << endl;
}