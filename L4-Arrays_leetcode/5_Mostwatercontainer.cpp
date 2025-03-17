// on leetcode
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int height[9] = {1,8,6,2,5,4,8,3,7};
    int n = sizeof(height) / sizeof(int);

    int s = 0;
    int e = n - 1;
    int ans = INT_MIN;
    while (s <= e){
        if (height[s] <= height[e]){
            ans = max(ans, (e-s) * height[s]);
            s++;
        }else{
            ans = max(ans, (e-s) * height[e]);
            e--;
        }
    }
    cout << ans << endl;
}
