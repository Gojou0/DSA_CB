#include<iostream>
#include<vector>
using namespace std;

int c = 0;

void Split(vector<int> &arr, int n, vector<int> &left, vector<int> &right, int i = 0){
    if (i == n){
        return;
    }

    left.push_back(arr[i]);
    for (int j = i; j < n; j++)
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<int> left;
    vector<int> right;

    Split(arr, n, left, right);

}