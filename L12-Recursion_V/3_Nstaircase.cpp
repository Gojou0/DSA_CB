#include<iostream>
#include<vector>
using namespace std;
vector<vector<int> >answer;

// Nth stair pr khade hone k liye (n-1 se lekr n-k) tk ke ways ka sum hoga

int Solve(int n, int k, vector<int> &ans){
    if (n < 0){
        return 0;
    }
    if (n == 0){
        answer.push_back(ans);
        return 1;
    }

    int cnt = 0;
    for (int j = 1; j <= k; j++){
        ans.push_back(j);
        cnt += Solve(n-j, k, ans);
        ans.pop_back();
    }
    return cnt;
}

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> ans;
    cout << Solve(n, k , ans) << endl;
    cout << endl;
    for (int i = 0; i < answer.size(); i++){
        for (int j = 0; j < answer[i].size(); j++){
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }
}