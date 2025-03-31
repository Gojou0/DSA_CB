#include <iostream>
#include <vector>
using namespace std;
int binarySearch(vector<int> &arr, int s, int e, int key){
    // Base case
    if (s > e) return -1;

    //Recursive case
    int mid = s + (e - s) / 2;
    if (arr[mid] == key) return mid;
    else if(key > arr[mid]){
        return binarySearch(arr, mid+1, e, key);
    }else{
        return binarySearch(arr, s, mid-1, key);
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

    cout << binarySearch(arr, 0, n-1, 3) << endl;
}