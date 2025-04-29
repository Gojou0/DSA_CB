#include<iostream>
#include<vector>
#include<map>
using namespace std;

// Remove Rebellious Nodes ... jinki khud ki bbhi respect na ho....and jo kisi ki kre bhi na

int main(){
    map<int,vector<int>> mp;
    vector<int> res;
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int p,r;
        cin>>p>>r;
        res.push_back(r);
        mp[p].push_back(i);
    }

    for (int i = 1; i <= n; i++){
        if (res[i-1] == 1){
            bool found = false;
            for (int j = 0; j < mp[i].size(); j++){
                if (res[mp[i][j] - 1] == 0){
                    found = true;
                    break;
                }
            }
            if (found == false){
                cout << i << " ";
            }
        }
    }


    // int n; 
    // cin >> n;
    // vector<int> adj[n+1];               // vector of array....vector consist of parents and each array consist its children
    // int res[n+1];
    // for (int i = 1; i <= n; i++){
    //     int p, r;
    //     cin >> p >> r;
    //     res[i] = r;
    //     if (p != -1){
    //         adj[p].push_back(i);
    //     }
    // }

    // for (int i = 1; i <= n; i++){
    //     if (res[i] == 1){
    //         bool found = false;
    //         for (int j = 0; j < adj[i].size(); j++){
    //             if (res[adj[i][j]] == 0){
    //                 found = true;
    //                 break;
    //             }
    //         }
    //         if (found == false){
    //             cout << i << " ";
    //         }
    //     }
    // }
}