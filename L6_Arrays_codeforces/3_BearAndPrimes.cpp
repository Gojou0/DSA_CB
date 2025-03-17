#include <iostream>
#include <vector>
using namespace std;

int MAX_VAL = 1e7 + 5;
vector <bool> primes(MAX_VAL, true);
vector <int> frequency(MAX_VAL, 0);
vector <int> multiple(MAX_VAL, 0);
vector <int> ps(MAX_VAL, 0);

void seive(){                                           // function to check prime number using primesieve theorem
    primes[0] = primes[1] = false;
    for (int i = 2; i * i < MAX_VAL; i++){
        if (primes[i] == true){
            for (int j = i*i; j < MAX_VAL; j += i){
                primes[j] = false;
            }
        }
    }
}

int main(){

    // OPTIMAL APPROACH

    seive();
    int n;
    cin >> n;

    for (int i = 0; i < n; i++){                    // to input elements and simultaneously calculating their frequency
        int x;
        cin >> x;
        frequency[x]++;
    }

    for (int i = 2; i < MAX_VAL; i++){              // create a multiple array jisme prime number k multiple jo given array me h unki 
        if (primes[i]){                             // frequency add krenge
           for (int j = i; j < MAX_VAL; j += i){
            multiple[i] += frequency[j];
           }
        }
    }

    ps[0] = ps[1] = 0;                              // create prefix sum array from multiple sum array
    for (int i = 2; i < MAX_VAL; i++){
        ps[i] = ps [i-1] + multiple[i];
    }

    int m;
    cin >> m;
    
    for (int i = 0; i < m; i++){
        int li, ri;
        cin >> li >> ri;
        li = min(li, MAX_VAL - 1);
        ri = min(ri, MAX_VAL - 1);
        cout << ps[ri] - ps[li-1] << endl;              // use prefix sum concept
    }
    
    // BRUTE FORCE APPROACH

    // int z = 0;
    // while (z < m){
    //     int ans = 0;
    //     for (int i = li[z]; i <= ri[z]; i++){
    //         int j = 2; 
    //         while (j < i){
    //             if (i % j == 0){
    //                 break;
    //             }
    //             j++;
    //         }
    //         if (j == i){
    //             for (int k = 0; k < n; k++){
    //                 if (a[k] % i == 0){
    //                     ans++;
    //                 }
    //             }
    //         }
    //     }
    //     cout << ans << endl;
    //     z++;
    // }

}