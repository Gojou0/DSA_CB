#include <iostream>
#include <vector>
using namespace std;

// Badi problem -> N disks ko destiination m rkhna h
// Choti problem -> N-1 disks ko karalo ...lekin pehle helper(aux) wali rod me kyuki nth wali disk pehle aaegi na destination me

// ** jab sabse badi disk hi hamne recusrion ko nhi di ..to wo kbhi badi disk uper rkhega hi nhi **


// Approach
// 1-> N-1 disks ko src se helper pr rkhwado with help of recusrion
// 2-> Nth disk ko src se destination pr dalo khud
// 3-> N-1 disks helper se destination pr dalwao with help of recusrsion


void TowerofHanoi(int n, char src, char helper, char des){
    // Base case
    if (n == 0) return; 

    // Recusrsive case
    TowerofHanoi(n-1, src, des, helper);                    // isme recursion des ko helper smjhke n-1 disks helper pr daldega
    cout << n << " -> " << src << " to " << des << endl;
    TowerofHanoi(n-1, helper, src, des);                    // isme recusrion src ko as helper use krega 
}

int main(){
    int n = 3;
    TowerofHanoi(n, 'A', 'B', 'C');
}