#include <iostream>
using namespace std;

int main(){
    int n;
    int a[5] = {3,4,5,1,2};
    n = 5;
    int s = 0;
    int e = n - 1;
    int ans = INT_MAX;
    while (s <= e){
        int mid = s + (e - s) / 2;
        if (a[mid] >= a[s]){                // identify sorted half
            ans = min(ans, a[s]);               // take minimum element from it and eliminate it
            s = mid + 1;
        }else{
            ans = min(ans, a[mid]);
            e = mid - 1;
        }
    }
    cout << ans << endl;
} 