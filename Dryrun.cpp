#include<iostream>
#include<vector>
using namespace std;
// int n;
// vector<int> visited;
// int solve(vector<int> &arr, int i){
//     if(i > n) return 0;
//     if(i == n){
//         return 0;
//     }

//     int ans1 = 0;
//     int ans2 = 0;

//     if (!visited[i]){
//         visited[i] = 1;
//         ans1 = 1 + solve(arr,i+1);
//         if(i + arr[i] >=0){
//             ans2 = 1 + solve(arr,i+arr[i]);
//         }else{
//             ans2 = INT_MAX;
//         }
//         visited[i] = 0;
//     }

//     return min(ans1,ans2);
// }

int main(){
    cin >> n;
    vector<int> arr(n,0);
    visited.resize(n,0);

    for(int i =0;i<n;i++) cin >> arr[i];
    

    cout << solve(arr,0);
}

void Solve(int n, int i){
    if (n == 12){
        cout << 12 << " ";
        return;
    }

    cout << n << " ";
    Solve(n+2, i+1);
    if (i % 2 == 0){
        cout << n + 2 << " ";
    }
}

int main(){
    int d = 2;
    Solve(2, 0);
}
