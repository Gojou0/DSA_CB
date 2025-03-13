#include <iostream>
using namespace std;

int main(){
    int a[] = {1,2,2};
    int a_size = sizeof(a) / sizeof(int);
    int n = 5;
    int sum = 0;     // kitna sum ban skta h
    int NNN = 1;     // agla number kya chahiye
    int i = 0;
    int patch = 0;
    while(sum < n){
        if(i < a_size && NNN >= a[i]){    // patching nhi hogi
            sum += a[i];
            NNN = sum + 1;
            i++;
        }else{                            // patching hogi
            sum += NNN;
            NNN = sum + 1;
            patch++;
        }
    }
    cout << "Minimum no. of Patches reuired : " << patch << endl;
}