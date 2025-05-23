#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void dfs(int u, int v, int par, int cost, vector<vector<int> > adj, vector<vector<int> > weight, int &ans){
    if (u == v){
        ans += cost;
    }

    for (int j = 0; j < adj[u].size(); j++){
        int adjacent = adj[u][j];
        if (adjacent != par){
            dfs(adjacent, v, u, cost+weight[u][adjacent], adj, weight, ans);
        }
    }
}

int main(){
    int n, r, m;
    cin >> n >> r >> m;
    vector<vector<int> > weight(n+1, vector<int> (n+1));
    vector<vector<int> > adj(n+1);
    for (int i = 0; i < n-1; i++){
        int u, v , w;
        cin >> u >> v >> w;
        weight[u][v] = w;
        weight[v][u] = w;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int q;
    cin >> q;
    int ans = 0;
    while (q--){
        int t;
        cin >> t;
        int u, v, w;
        cin >> u >> v >> w;
        if (t == 1){
            dfs(u, v, -1, 0, adj, weight, ans);                 // take par as -1 as we don;t know its parent
        }else{
            weight[u][v] = w;
            weight[v][u] = w;
        }
    }

    cout << ans << endl;
}