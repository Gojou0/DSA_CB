#include<iostream>
#include<deque>
#include<vector>
using namespace std;

vector<int> SW(vector<int> &arr, int k){
    int n = arr.size();
    vector<int> ans;
    deque<int> q;               // use deque ..bcoz we have to pop from both side and push only from back or top
    for (int i = 0; i < n; i++){
        if (!q.empty() && q.front() <= i-k){                // agr sliding window se bahar ka index front pr h to use pop krdo
            q.pop_front();
        }
        while (!q.empty() && arr[q.back()] <= arr[i]){      // use deque as monotonic stack to store elements in decreasing order..
            q.pop_back();                               // mtlb top(back) pr sbse chota hoga or front pr sbse bda  wahi se to ans milega
        }
        q.push_back(i);
        if (i >= k-1) ans.push_back(arr[q.front()]);            // agr sliding window k end pr aagye to ans me value daldo front se
    }
    return ans;
}

int main(){
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(-1);
    arr.push_back(-3);
    arr.push_back(5);
    arr.push_back(3);
    arr.push_back(6);
    arr.push_back(7);
    
    int k;
    cin >>k;

    vector<int> ans = SW(arr, k);
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}