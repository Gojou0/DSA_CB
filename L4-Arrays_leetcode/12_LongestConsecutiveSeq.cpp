#include <iostream>
using namespace std;

int main(){
    int a[] = {100,4,5,200,1,3,2};
    int n = sizeof(a) / sizeof(int);

    //USING SORTING
    sort(a,a+n);
    int cnt = 0;
    int previouselement = INT_MIN;          //previouselement of sequence
    int longest = 1;
    for (int i = 0; i < n; i++){
        if (previouselement == a[i] - 1){           //agr current element se ek kam hamari sequence ka previous element h tbhi current
            cnt++;                                  // element bhi hamari sequence me aa skta h
            longest = max(longest, cnt);
            previouselement = a[i];
        }else if (previouselement == a[i]){             //just to deal with duplicacy
            continue;
        }else{                                      // agr equal ya ek kam nhi h previous element ..iska mtlb naya sequence bnao or
            cnt = 1;                                // current element ko hamari nayi sequence ka previous element daldo
            previouselement = a[i];
        }
    }
    cout << longest << endl;


    // Without Sorting
    // Use map data structure as searching in map requires O(1) time complexity

}