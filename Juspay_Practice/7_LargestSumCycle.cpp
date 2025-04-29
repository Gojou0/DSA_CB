#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

int Solve(vector<int> &arr){
    map<int, int> indegree;
    for (auto i : arr){
        if (i != -1) indegree[i]++;
    }

    int ans = INT_MIN;
    int n = arr.size();
    vector<int> temp;
    queue<int> q;
    vector<int> vis(n, false);

    for (int i = 0; i < n; i++){
        if (indegree[i] == 0) q.push(i);                // since, cycle can be from anywhere
    }

    while (!q.empty()){
        int curr = q.front();
        q.pop();

        if (arr[curr] != -1){
            int next = arr[curr];
            indegree[next]--;
            if (indegree[next] == 0){
                q.push(next);             // including only nodes which are not part of cycle....queue is used to delete non-cycle nodes
            }                               // deletion can be done by making their indegree 0;
        }
    }

    for (int i = 0; i < n; i++){
        if (indegree[i] == 0 || vis[i]) continue;             // skip non cylce nodes and skip cycle nodes which are already visited
        
        int j = i;
        int sum = 0;
        while (!vis[j]){
            sum += j;
            vis[j] = true;
            j = arr[j];
        }
        ans = max(ans, sum);
    }

    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << Solve(arr) << endl;

}