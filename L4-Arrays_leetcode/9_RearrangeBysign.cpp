// on leetcode
#include <iostream>
using namespace std;

int main(){
    int nums[6] = {3,1,-2,-5,2,-4};
    int n = 6;
    int ans[n];
    int pos = 0;
    int neg = 1;
    for (int i = 0; i < n; i++){
        if (nums[i] > 0){
            ans[pos] = nums[i];
            pos += 2;
        }else{
            ans[neg] = nums[i];
            neg += 2;
        }
    }
    for (int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
}