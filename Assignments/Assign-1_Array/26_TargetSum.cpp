#include<iostream>
#include<vector>
using namespace std;

int Solve(vector<int> &arr, int target, vector<int> &temp, int i = 0){
    if (target == 0 && i == arr.size()){
        return 1;
    }

    if (i == arr.size()){
        return 0;
    }

    int cnt = 0;
    temp.push_back(+arr[i]);
    cnt += Solve(arr, target-arr[i], temp, i+1);
    temp.pop_back();

    temp.push_back(-arr[i]);
    cnt += Solve(arr, target+arr[i], temp, i+1);
    temp.pop_back();

    return cnt;
}

int main(){
    int n, target;
    cin >> n >> target;

    vector<int> arr(n,0);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<int> temp;
    cout << Solve(arr, target, temp) << endl;
}