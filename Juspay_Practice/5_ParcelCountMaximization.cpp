#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// sq[i] = {.....} 
// perm[i] = {.....}    this can be from 1 to n in any order
// Maximum same ele in sq[i] + perm[i]

int main(){
    int n;
    cin >> n;
    vector<int> arr(n,0);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    // Same elements bnane k liye permutation ko sequence se ulte order me krna padega...tbhi maximum same element bn skte h
    int ans = INT_MIN;
    for (int i = 0; i < n; i++){
        int j = i;                          // har position se check krne k liye
        int same = 0;
        while (arr[j] < (arr[i] + n) && j < n){                   // max element sequence k (smaller element + n-1) hi ho skta h 
            if (arr[j] == arr[j+1]) same++;             // agr sequence me repeating ele ho ..to skip krdo
            j++;
        }
        ans = max(ans, (j-i) - same);
    }

    cout << ans << endl;
}