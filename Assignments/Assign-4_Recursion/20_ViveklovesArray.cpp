#include<iostream>
#include<vector>
using namespace std;

int Partition(vector<int> &arr, int i, int j, int k = 0){
    if (k == j-1){
        return 0;
    }

    if (j-i <= 1){
        return 0;
    }

    int leftsum = 0;
    for (int x = i; x <= k; x++){
        leftsum += arr[x];
    }

    int rightsum = 0;
    for (int x = k+1; x < j; x++){
        rightsum += arr[x];
    }

    int ans = 0;
    int cnt1 = 0;
    int cnt2 = 0;

    if (leftsum != rightsum){
        ans += Partition(arr, i, j, k+1);
    }

    if (leftsum == rightsum){
        cnt1 = 1;
        cnt2 = 1;
        cnt1 += Partition(arr,i, k+1);
        cnt2 += Partition(arr,k+1, j);
        ans = max(cnt1, cnt2);
    }

    return ans;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> arr(n,0);
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }

        cout << Partition(arr, 0, n) << endl;
    }
}