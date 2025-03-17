#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){
    int a[3] ={1,2,3};
    int n = 3;
    int k = 3;
    unordered_map<int, int> mp;
    mp[0] = 1;
    int ps = 0;
    int c = 0;
    for (int i = 0; i < n; i++){
        ps += a[i];
        int rem = ps - k;               
        if (mp.find(rem) != mp.end()){              //check for remaining sum and add its freuqency
            c += mp[rem];
        }
        mp[ps]++;               // update frequency of ps
    }
    cout << c <<endl;
}