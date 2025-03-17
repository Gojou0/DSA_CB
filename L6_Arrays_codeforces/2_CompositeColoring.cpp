#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int prime[11] = {2,3,5,7,11,13,17,19,23,29,31};                 // kyuki 11  tk colors hi allowed
        int n;
        cin >> n;
        int a[1005];

        for (int i = 0; i < n; i++){
            cin >> a[i];
        }

        int colored[1005] = {0};                        //colored elements dene k liye
        int color = 1;                                  // iski value kbhi bhi 11 se jyada nhi ho skti
        for (int j = 0; j < 11; j++){
            int x = prime[j];
            bool kyacolorhua = false;                   //color hua ya nhi check krne k liye
            for (int i = 0; i < n; i++){
                if (colored[i] != 0){
                    continue;               //ek baari jis pr rang h us per dubara nhi krna
                }
                if (a[i] % x == 0){                     //check element's divisiblity bt prime numbers and give them same color
                    colored[i] = color;
                    kyacolorhua = true;
                }
            }
            if (kyacolorhua == true){               //agr color hua tbhi next color pr jaenge
                color++;
            }
        }
        cout << color - 1 << endl;                  // last me color extra bdaya tha isliye
        for (int i = 0; i < n; i++){
            cout << colored[i] << " ";
        }
    }
}