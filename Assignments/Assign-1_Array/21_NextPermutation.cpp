#include<bits/stdc++.h>
using namespace std;
int main() {
	int n; 
	cin >> n;
	int nums[n];
	for (int i = 0; i < n; i++){
		cin >> nums[i];
	}
	int index = -1;
	for (int i = n - 2; i >= 0; i--){
		if (nums[i] < nums[i+1]){
			index = i;
			break;
		}
	}
	if (index == -1){
		reverse(nums, nums+n);
	}else{
		for (int i = n - 1; i > index; i--){
			if (nums[i] > nums[index]){
				swap(nums[index], nums[i]);
				break;
			}
		}
		reverse(nums+index+1, nums+n);
	}
	for (int i = 0; i < n; i++){
		cout << nums[i] << " ";
	}
	
	return 0;
}