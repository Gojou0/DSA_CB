#include <iostream>
#include <vector>
using namespace std;

void Merge(vector<int> &arr, int s, int e, int q){
    vector<int> l1;
    vector<int> l2;
    for (int i = s; i <= q; i++){
        l1.push_back(arr[i]);
    }
    for (int i = q+1; i <= e; i++){
        l2.push_back(arr[i]);
    }

    int i = 0;
    int j = 0;
    int k = s;
    while (i < l1.size() && j < l2.size()){
        if (l1[i] < l2[j]){
            arr[k] = l1[i];
            i++;
            k++;
        }else{
            arr[k] = l2[j];
            j++;
            k++;
        }
    }
    while (i < l1.size()){
        arr[k] = l1[i];
        i++;
        k++;
    }
    while (j < l2.size()){
        arr[k] = l2[j];
        j++;
        k++;
    }
}

void MergeSort(vector<int> &arr, int s, int e){
    // Base case
    if (s >= e) return;

    // Recursive case
    int q = (s + e) / 2;
    MergeSort(arr, s, q);           // Dividing
    MergeSort(arr, q+1, e);
    Merge(arr, s, e, q);               // Conquering
}

int main(){
    vector<int> arr;
    arr.push_back(5);
    arr.push_back(4);
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(1);
    int n = arr.size();

    MergeSort(arr, 0, n-1);

    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}