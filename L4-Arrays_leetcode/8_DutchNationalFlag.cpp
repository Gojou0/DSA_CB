// [0......low -1]  -->  0 or extreme left
// [low.........mid-1] -->  1 or sorted middle
// [mid..........high]  --> unsorted middle or on which we have to work with algo
// [high+1........n-1]  --> 2 or extreme right
#include <iostream>
using namespace std;

int main(){
    int nums[] = {2,0,2,1,1,0};
    int n = 6;

    int low = 0;
    int high = n - 1;
    int mid = 0;
    while (mid <= high){
        if (nums[mid] == 0){                                // agr zero value h toh exterme left wale k last me bhejdo
            swap(nums[mid],nums[low]);
            low++;
            mid++;
        }else if (nums[mid] == 1){                          // agr 1 value h toh sorted middle k last me bhejo yani bas mid badao
            mid++;
        }else{
            swap(nums[mid], nums[high]);                    // agr 2 h extreme right wale k starting m bhejo
            high--;
        }
    }
    for (int i = 0; i < n; i++){
        cout << nums[i] << " ";
    }
}