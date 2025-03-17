#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[100005];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int left[100005] = {0};
    int right[100005] = {0};
    
    left[0] = INT_MIN;
    for (int i = 1; i < n; i++){
        left[i] = max(left[i-1],a[i-1]);
    }

    right[n-1] = a[n-1];
    for (int i = n-2; i >=0; i--){
        right[i] = min(right[i+1],a[i]);
    }

    int partition = 1;
    for (int i = 1; i < n; i++){
        if (left[i] <= right[i]){
            partition++;
        }
    }
    cout << partition;

    return 0;
}