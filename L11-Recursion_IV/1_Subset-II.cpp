#include<iostream>
#include<vector>
using namespace std;

// Badi problem -> sabke subsets generate krane h
// Choti problem -> ek br bina first index k subsets nikalwao (not take) and ek br unko niklwa ke unme first index add krdo (take)

// Recurrence relation
// BP = CP1 + CP2
// BP = S(a, i+1) + (i, s(a, i+1))

void Subsets(int* a, int* b, int n, int i, int j){
    // Base case
    if (i == n){
        for (int k = 0; k < j; k++){
            cout << b[k] << " ";
        }
        cout << endl;
        return;
    }

    // Recursive case

    // 1-> ith ko le lo b me
    b[j] = a[i];
    Subsets(a, b, n, i+1, j+1);
    while (i+1 < n && a[i] == a[i+1]) i++;
    // 2-> ith ko mat lo b me
    Subsets(a, b, n, i+1, j);
}


int main(){
    int a[] = {1,2,2};
    int b[200];
    int n = sizeof(a) / sizeof(int);

    Subsets(a, b, n, 0, 0);
    
    return 0;
}