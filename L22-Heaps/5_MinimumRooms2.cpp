#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

int Solve(vector<vector<int>> &arr){
    sort(arr.begin(), arr.end());
    priority_queue<int, vector<int>, greater<int>> heap;

    for (auto i : arr){
        if (!heap.empty() && i[0] >= heap.top()){   /// run meeting parallely in same room
            heap.pop();
            heap.push(i[1]);
        }else{                  // make seperate room
            heap.push(i[1]);
        }
    }

    return heap.size();
}

int main(){
    vector<vector<int> > arr;
    arr.push_back({0,30});
    arr.push_back({5,10});
    arr.push_back({15,20});

    int ans = Solve(arr);
    cout << ans << endl;
}