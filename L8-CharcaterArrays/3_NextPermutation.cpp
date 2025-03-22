#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    char a[100];
    cin >> a;
    int n = strlen(a);

    int index = -1;
    for (int i = n-2; i >= 0; i--){
        if (a[i] < a[i+1]){
            index = i;
            break;
        }
    }

    if (index == -1){
        reverse(a, a+n);
    }else{
        for (int i = n -1; i >= 0; i--){
            if (a[i] > a[index]){
                swap(a[i], a[index]);
            }
        }
        reverse(a+ index +1, a +n);
    }

    cout << a << endl;
}