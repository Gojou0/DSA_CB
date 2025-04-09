#include<iostream>
using namespace std;

int Partition(int* arr, int s, int e){
    int p = e;
    int i = s-1;
    int j = s;
    while (j < e){
        if (arr[j] <= arr[p]){
            i++;                                        // agr pivot se chota h to seg1 ka size badakr usme add krdo wo by swapping
            swap(arr[i], arr[j]);
        }
        j++;                                // seg2 apne aap badta rhega j k sath agr pivot se bda hoga toh
    }                                               
    swap(arr[i+1], arr[p]);                 // pivot element ko seg1 and seg2 k middle m krdo
    return i+1;
}

void Quicksort(int* arr, int s, int e){
    if (s > e) return ;

    int index = Partition(arr, s, e);
    Quicksort(arr, s, index-1);
    Quicksort(arr, index+1, e);
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    Quicksort(arr, 0, n - 1);
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}