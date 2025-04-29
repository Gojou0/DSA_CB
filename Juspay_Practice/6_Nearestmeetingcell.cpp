#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Cell with minimum sum of distance of it from two diffrent points or nodes will be the nearest meeting cell

void BFS(int src, vector<int> &arr, vector<int> &dis){
    int n = arr.size();
    vector<bool> vis(n, false);
    queue<int> q;
    q.push(src);
    dis[src] = 0;
    vis[src] = true;

    while (!q.empty()){
        int curr = q.front();
        q.pop();
        
        int next = arr[curr];
        if (next != -1 && !vis[next]){
            dis[next] = dis[curr] + 1;
            vis[next] = true;                       // as there are multi entry point...so it may reoccur
            q.push(next);           
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<int> dist1(n, INT_MAX), dist2(n, INT_MAX);
    int c1, c2;
    cin >> c1 >> c2;

    BFS(c1, arr, dist1);        // find distance of all nodes from both the sources
    BFS(c2, arr, dist2);

    int answer = -1;
    int minDist = INT_MAX;

    for (int i = 0; i < n; ++i) {               // now find the minimum sum of distances of both
        if (dist1[i] != INT_MAX && dist2[i] != INT_MAX) {
            int Dist = dist1[i] + dist2[i];
            if (Dist < minDist) {
                minDist = Dist;
                answer = i;
            }
        }
    }

    cout << answer << endl;
}
