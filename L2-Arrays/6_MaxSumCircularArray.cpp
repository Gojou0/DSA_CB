#include <iostream>
using namespace std;

int main(){
    int a[] = {2,2,-1,2,2};
    int n = sizeof(a) / sizeof(int);
    int sum = 0;
    int si , sj;
    int ans = INT_MAX;
    int ans_1 = INT_MIN;
    int ps[100] = {0};

    //Make Prefix sum array
    ps[0] = a[0];
    for(int i = 1; i < n; i++){
        ps[i] = ps[i-1] + a[i];
    }

    //Min Sum Algo
    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            sum = ps[j] - ( i-1 >= 0 ? ps[i-1] : 0);
            if (sum < ans){
                ans = sum;
                si = i;
                sj = j;
            }  
        }
    }

    //Min Sum using Kadane's Algo
    // for (int i = 0 ; i < n; i++){
    //     a[i] = -a[i];
    // }

    // bool isPositivePresent = false;
    // for (int i = 0; i < n; i++){
    //     if(a[i] > 0) {
    //         isPositivePresent = true;
    //     }
    //     ans = max(ans,a[i]);
    // }

    // if (isPositivePresent == true){
    //     //Max Sum Algo
    //     for(int i = 0; i < n; i++){
    //         sum += a[i]; //ELements ko add krte jao
    //         if (sum < 0) sum = 0; //agr -ve aaye toh zero krdo
    //         ans = max(ans, sum); // ans ke andar max lete jao
    //     }
    // }

    // Option - 1: Corner Sum
    int c_sum = ps[n-1] - (ans);  // Total Sum mei se Minimum subtract kr diya

    // Option -2: Max Sum
    //Max Sum Algo
    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            sum = ps[j] - ( i-1 >= 0 ? ps[i-1] : 0);
            if (sum > ans_1){
                ans_1 = sum;
                si = i;
                sj = j;
            }   
        }
    }

    cout << " Max Sum In Circular Array :" << max(c_sum,ans_1) << endl;

    return 0;
}