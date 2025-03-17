#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> a;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){            // take inputs
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    bool contains1 = false;                 // to check ki array m 1 h ya nhi
    for (int i = 0; i < n; i++){
        if (a[i] == 1){
            contains1 = true;
            break;
        }
    }
    if (contains1 == false){                // agr 1 nhi h to first positive wahi hoga
        cout << 1 << endl;
    }else{
        for (int i = 0; i < n; i++){
            if (a[i] < 1 || a[i] > n){              // negative + 0 and n se bade number se mtlb nhi ..isliye unhe 1 bna do
                a[i] = 1;
            }
        }
        int index;
        for (int i = 0; i < n; i++){
            index = abs(a[i]) - 1;                  // jo number present hoga usko index se encode krdo ...mtlb index+1 no. represent krega
            if (a[index] < 0){                      // ager pehle hi -ve kr dia ho to skip
                continue;
            }else{
                a[index] = -a[index];               // har number me ek kam kro or use value ko as index use krke wah -ve krdo
            }
        }
        bool flag = false;
        for (int i = 0; i < n; i++){
            if (a[i] > 0){                          // now agr koi value positive bachi h ..toh wahi first possitive h 
                cout << i + 1 << endl;              // decode krke nikal lo value
                flag = true;
                break;
            }
        }
        if (flag == false){                         // agr sab -ve hi ho gyi values mtlb n + 1 will be answer
            cout << n + 1 << endl;
        }
    }
}