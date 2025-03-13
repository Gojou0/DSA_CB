#include <iostream>
using namespace std;

double median(int *a, int *b, int n, int m){
    if( n > m ) return median(b, a, m, n);
    
    int s = 0;              // 0 elements left part me jaenge
    int e = n;              // n elements left part me jaenge
    while(s <= e){
        int mid = (s + e) / 2;    //yaha tak a left elements
        int mid1 = (n + m + 1) / 2 - mid;     //yaha tak left elements b ke

        int leftmax_a = (mid > 0) ? a[mid - 1] : INT_MIN;
        int leftmax_b = (mid1 > 0) ? b[mid1 - 1] : INT_MIN;
        int rightmin_a = (mid < n) ? a[mid] : INT_MAX;
        int rightmin_b = (mid1 < m) ? b[mid1] : INT_MAX;
 
        if (leftmax_a <= rightmin_b && leftmax_b <= rightmin_a){          // condition true matlab answer mil gya
            if (((n + m) % 2) == 1) return max(leftmax_a,leftmax_b);
            else{
                long long x = max(leftmax_a,leftmax_b);
                long long y = min(rightmin_a,rightmin_b);
                return (x + y) / 2.0;
            }
        }else if (leftmax_a > rightmin_b){         //condition 1 galat ho gyi to a me se ek kam kr denge
            e = mid - 1;
        }else{                                     //condition 2 galat ho gyi to a me ek bada denge
            s = mid + 1;
        }
    }
    return -1;
}

int main(){
    int a[] = {1,2};
    int b[] = {3,4};
    int n = sizeof(a) / sizeof(int);
    int m = sizeof(b) / sizeof(int);

    cout << median(a, b, n, m);
}