#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int ans = INT_MAX;
    for (int i = 0; i < n; i++){            // to check in different windows
        int j = i;
        while (j < n && arr[j] < arr[i] + n){
            j++;
        }
        int moves = n - (j - i);            // j-i gives the number of elements that are present in window which we require..
        ans = min(ans, moves);
    }

    cout << ans << endl;
}
