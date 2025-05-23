#include<iostream>
#include<vector>
using namespace std;

void dfs(int curr, int pr, int cnt, vector<vector<int> > adj, vector<int> safeness, int &ans, int m){
    if (safeness[curr] == 0){           // consecutive me increment
        cnt++;
    }else{              //  jump me zero
        cnt = 0;
    }

    if (cnt > m) return;

    bool leaf = true;

    for (int j = 0; j < adj[curr].size(); j++){                
        int next = adj[curr][j];
        if (next == pr) continue;
        leaf = false;                    // agr leaf hoga to parent k alawa koi adjacent nhi hoga
        dfs(next, curr, cnt, adj, safeness, ans, m);
    }

    if (leaf && safeness[curr] == 1){
        ans++;
    }
}

int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> safeness(n+1);
    int edges;
    cin >> edges;
    for (int i = 1; i <= n; i++){
        cin >> safeness[i];
    }

    vector<vector<int> > adj(n+1);

    while (edges--){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;
    dfs(1, -1, 0, adj, safeness, ans, m);

    cout << ans << endl;
}