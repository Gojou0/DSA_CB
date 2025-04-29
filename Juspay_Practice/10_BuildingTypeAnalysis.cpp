#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int> > buildings(n, vector<int> (m,0));
    map<int, vector<int> > freqx;
    map<int, vector<int> > freqy;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> buildings[i][j];
            freqx[buildings[i][j]].push_back(i);
            freqy[buildings[i][j]].push_back(j);
        }
    }

    int ans = 0;
    for (auto x : freqx){
        sort(x.second.begin(), x.second.end());         // sort is done to prevent absolute diff problem
        int size = x.second.size();
        vector<int> suffx(size);               

        suffx[size-1] = x.second.back();
        for (int i = size-2; i >= 0; i--){
            suffx[i] = suffx[i+1] + x.second[i];                // Calculate prefix sum for x axis
        }

        for (int j = 0; j < size-1; j++){
            ans += suffx[j+1] - (x.second[j] * (size - 1 - j));             // now sum will be sum of aage ke pairs and their diff from curr pair * size-1-j
        }
    }

    for (auto y : freqy){
        sort(y.second.begin(), y.second.end());
        int size = y.second.size();
        vector<int> suffy(size);

        suffy[size-1] = y.second.back();
        for (int i = size-2; i >= 0; i--){
            suffy[i] = suffy[i+1] + y.second[i];                // Calculate prefix sum for y axis
        }           

        for (int j = 0; j < size-1; j++){
            ans += suffy[j+1] - (y.second[j] * (size - 1 - j));
        }
    }

    cout << ans << endl;
}