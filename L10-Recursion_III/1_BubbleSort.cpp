#include <iostream>
#include <vector>
using namespace std;

// Badi problem -> N-1 numbers ko sahi jagah place krna ...kyuki last automatic ho jaega

// Choti problem -> N-2 numbers ko sahi jagah place krna 

// Recursion is follow as:
// BP = CP + ek ko sahi jagah rkhna

void BubbleSortLoop(vector<int> &arr, int n, int i){
    // Base case
    if (i == n-1) return;           // i index h (0 se st hua) and n-1 element ka number h and ye to sorted hi hoga

    // ek ko sahi jagah rkhna
    for (int j = 0; j < n-1-i; j++){
        if (arr[j] > arr[j+1]) {
            swap(arr[j], arr[j+1]);
        }
    }

    // Recursive case
    BubbleSortLoop(arr, n, i+1);                // Assume ki choti solve ho jaegi
}

void BubbleSort(vector<int> &arr, int n, int i, int j){
    // Base case
    if (i == n-1) return;

    // Recursive case
    if (j == n-i-1){
        BubbleSort(arr, n, i+1, 0);           // jab j last element pr aaega tbhi i badega
    }else{
        if (arr[j] > arr[j+1]){
            swap(arr[j], arr[j+1]);
        }
        BubbleSort(arr, n, i, j+1);             // j k loop ko hatane k liye j as argument pass krdia and use increment krte gye
    }
}

int main(){
    vector<int> arr;
    arr.push_back(5);
    arr.push_back(4);
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(1);
    int n = arr.size();

    BubbleSort(arr, n, 0, 0);

    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}