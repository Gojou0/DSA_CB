#include<iostream>
#include<vector>
#include<map>
using namespace std;

int Find(vector<int> &arr){
    map<int, int> mp;
    for (int i = 0; i < arr.size(); i++){
        if (arr[i] > -1) mp[arr[i]] += i;
    }

    int ans = INT_MIN;
    int answer = 0;
    for (auto &p : mp) {
        if (p.second >= ans) {
            answer = p.first;
            ans = p.second;
        }
    }    

    return answer;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << Find(arr) << endl;
}

