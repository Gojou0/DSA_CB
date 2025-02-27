#include <iostream>
using namespace std;

int main(){
    int a[]= {1,2,3,4,5,};
    int n = sizeof(a) / sizeof(int);

    int res[100];
    for( int i = 0; i < n; i++){
        res[i] = 1;
    }

    //left side k liye
    res[0] = 1;
    int ans = a[0];    //ith index se pehle ki value store krega
    for (int i = 1; i < n; i++){
        res[i] = ans;  //pehle add krdo array me
        ans *= a[i];   //fir next value ke liye ans ko update krdo
    }
    
    //right side ke liye
    ans = 1;      //ith ke baad wali values store krega
    for(int i = n-1; i >= 0; i--){
        res[i] *= ans;
        ans *= a[i];
    }

    for (int i = 0; i < n; i++){
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}