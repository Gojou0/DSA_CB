#include<iostream>
using namespace std;

// Recursive
int Ncr(int n, int r){
    if (r == 0) return 1;
    if (r == 1) return n;

    return Ncr(n,r-1) * ((n-r+1) / r);
}

// Loop
int Ncrloop(int n, int r){
    int ans = 1;
    for (int i = 1; i <= r; i++){
        ans *= (n-i+1);
        ans /= i;
    }
    return ans;
}

int main(){
    int n, r;
    cin >> n >> r;

    int ans = Ncrloop(n,r);
    cout << ans << endl;
}