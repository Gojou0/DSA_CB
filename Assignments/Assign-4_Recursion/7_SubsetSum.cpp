#include<iostream>
#include<vector>
using namespace std;

void Subsetsum(vector<int> &arr, int target, int i, vector<int> &temp, vector<vector<int> > &ans){
    if (i == arr.size()){
        int sum = 0;
        for (int k = 0; k < temp.size(); k++){
            sum += temp[k];
        }
        if (sum == target){
            ans.push_back(temp);
        }
        return;
    }
    

    temp.push_back(arr[i]);
    Subsetsum(arr, target, i+1, temp, ans);
    temp.pop_back();
    Subsetsum(arr, target, i+1, temp, ans);
}


int main(){
    int n;
    cin >> n;
    vector<int> arr(n,0);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int target;
    cin >> target;
    int c;
    vector<vector<int> > ans;
    vector<int> temp;
    Subsetsum(arr, target, 0, temp, ans);

    for (int i = 0; i < ans.size(); i++){
        for (int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << " ";
    }
    cout << endl;
    cout << ans.size() << endl;
}