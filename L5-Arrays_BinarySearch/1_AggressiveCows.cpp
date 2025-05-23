#include <iostream>
#include <algorithm>
using namespace std;


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