#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<string> ans;

void MazePath(vector<vector<int> > arr, string temp, int i, int j){
    if (i == arr.size()-1 && j == arr[0].size()-1){
        ans.push_back(temp);
        return;
    }

    if (i + 1 < arr.size()){
        temp += 'V';
        MazePath(arr, temp, i+1, j);
        temp.pop_back();
    }

    if (j + 1 < arr[0].size()){
        temp += 'H';
        MazePath(arr, temp, i, j+1);
        temp.pop_back();
    }
}
    

int main(){
    int n; 
    cin >> n;
    int m ;
    cin >> m;
    vector<vector<int> > arr(n, vector<int> (m));
    string temp;

    MazePath(arr, temp, 0, 0);

    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << "";
        }
        cout << " ";
    }
    cout << endl;
    cout << ans.size() << endl;
}