#include <iostream>
#include <algorithm>
using namespace std;

// int main(){
//     int a[] = {1, 2, 8, 4, 9};
//     int n = sizeof(a) / sizeof(int);
//     int cows = 3;
//     sort(a, a+n);
//     int s = 0;
//     int e = 8;
//     int ans = INT_MIN;
    
//     while (s <= e){
//         cows = 3;
//         int mid = (s + e) / 2;
//         int i = 0;
//         while (i < n){
//             i = i + mid;
//             cows--;
//         }
//         if (cows == 0){ 
//             ans = max(mid, ans);
//         }
//         else if (cows > 0 ){
//             e = mid - 1;
//         }else{
//             s = mid + 1;
//         }
//     }

//     cout << ans;
//     return 0;
     
// }

int a[100005];
int n, cows;
int testcase;

bool KyacowsoplaceHopayi(int d){
    int cowsplaced = 1;
    int pc = a[0];
    for (int i = 1; i < n; i++){
        if (a[i] - pc >= d){
            cowsplaced++;
            pc = a[i];
            if (cowsplaced >= cows) return true;
        }
    }
    return false;
}

int aggressiveCows(int a[]){
    //find search space
    int s = 0, e = a[n-1] - a[0];
    int ans;

    while (s <= e){
        int mid = s + (e - s) / 2;
        if (KyacowsoplaceHopayi(mid) == true){
            ans = mid;
            s = mid + 1;
        }else{
            e = mid - 1;
        }
    }
    return ans;
}

int main(){
    cin >> testcase;
    
    while (testcase > 0){
        cin >> n >> cows;
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a,a+n);
        cout << aggressiveCows(a) << endl;

        testcase--;
    }
    
}