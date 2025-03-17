#include <iostream>
#include <algorithm>
//#include <functional>  
using namespace std;

int main(){
    int a[] = {-1,0,1,2,-1,-4};
    int n = sizeof(a) / sizeof(int);
    sort(a, a+n);     //sorting is mandatory
    
    for (int i = 0; i < n; i++){
        if (a[i] > 0) break;     // if all positive then no triplets
        if (i > 0 && a[i] == a[i-1]) continue;   //to prevent duplicacy in i
        int j = i+1;
        int k = n-1;
        while (j < k){
            if (a[j] + a[k] == -a[i]){
                cout << a[i] << " " << a[j] << " " << a[k] << endl;
                j++;
                k--;
                while (j < k && a[j] == a[j-1]) {    //to prevent duplicacy in j
                    j++;
                }
            }else if( a[j] + a[k] > -a[i]) {
                k--;
            }else{
                j++;
            }
        }
    }
}
