// on leetcode
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int a[3] = {0,0,0};
    int n = 3;
    int target = 1;
    sort(a, a+n);
    int minsum = a[0] + a[1] + a[2];
    
    for (int i = 0; i < n; i++){
        if (i > 0 && a[i] == a[i-1]) continue;
        int j = i + 1;
        int k = n - 1;
        while (j < k){
            int sum = a[i] + a[j] + a[k];
            if (abs(target - sum) < abs(target - minsum)){
                minsum = sum;
            }
            if (sum < target) {
                j++;
            }else if(sum > target){
                k--;
            }else{
                cout << sum << endl;
                break;
            }
        }
    }
    cout << minsum << endl;
}