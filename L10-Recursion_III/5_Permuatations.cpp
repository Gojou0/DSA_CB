#include<iostream>
#include<vector>
using namespace std;

// Badi Problem -> Print all permutation or it means saare elements swaps honge
// Choti Problem -> Pehle index k alawa baki swapping recursion se kralo

// Recurrence relation
// BP = CP + swapping for 1st index

void PrintPerm(string &arr, int n, int index){
    // Base case
    if (index == n){
        for (int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Recursive case
    for (int i = index; i < n; i++){            
        swap(arr[index], arr[i]);                   // 1st index ki swapping khud kri
        PrintPerm(arr,n,index+1);              // baki ki swapping recursion se krali  
        swap(arr[index], arr[i]);                   // swap back ...kyuki arr by address pass hua and values gets changed .. backtracking
    }
}

int main(){
    string arr = "abc";
    sort(arr.begin(), arr.end());
    int n = arr.size();
    PrintPerm(arr, n, 0);
    return 0;
}