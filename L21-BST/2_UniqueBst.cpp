#include<iostream>
using namespace std;

int Solve(int n, int i = 1){
    if (n == 0) return 1;       // it is not an input(always > 1)....agr left ya right me (i-1) or (n-i) 0 hua toh...ek permutation to hoga hi
    if (i > n) return 0;

    // Left nodes se kitne subtrees banenge -> Solve(i-1)
    // Right Nodes se kitne subtrees banenge -> Solve(n-i)
    int ans;
    ans = Solve(i-1) * Solve(n-i);              // number of permutation for current will be multiplication of left count and right count    

    return ans + Solve(n, i + 1);
}

int main(){
    int n;
    cin >> n;
    int ans = Solve(n);

    cout << ans << endl;
    return 0;
}