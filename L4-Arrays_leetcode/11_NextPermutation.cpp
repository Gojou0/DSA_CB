#include <iostream>
using namespace std;

// think it like dictionary
int main(){
    int a[] = {4,1,5,4,3};
    int n = sizeof(a) / sizeof(int);

    int index;
    bool dec = true;
    for (int i = n - 2; i >= 0; i--){               //to checkn larger same prefix or get a breakpoint
        if (a[i] < a[i+1]) {                         // hame index pr badi value dalni h or wo jab hi dalegi jab wo right me ho
            index = i;
            dec = false;
            break;
        }
    }
    if (dec == true) {                          // agr decreasing me hua to increasing hi next permute hoga
        reverse(a, a + n);
        for (int i = 0; i < n; i++){
            cout << a[i] << " ";
        }
    }else{
        for (int i = n - 1; i > index; i--){                //right me sabse choti lekin index se badi value nikalo
            if (a[i] > a[index]){
                swap(a[index],a[i]);
                break;
            }
        }
        reverse(a + index + 1,a + n);                       // ab right wale ko increasing me krdo just next permute k liye
        
        for (int  i = 0; i < n; i++){                       // print next permute
            cout << a[i] << " ";
        }
    }
}