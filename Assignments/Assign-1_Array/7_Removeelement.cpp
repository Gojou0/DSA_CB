#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int target;
    cin >> target;
    int i = 0;
    for (int j = i; j < n; j++){
        if (nums[j] != target){
            swap(nums[i],nums[j]);
            i++;
        }
    }
    for (int j = 0; j < i; j++){
        cout << nums[j] << " ";
    }
}