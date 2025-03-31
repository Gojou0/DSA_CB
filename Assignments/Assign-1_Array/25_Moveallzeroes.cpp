#include<iostream>
using namespace std;
int main () {
	int n;
	cin >> n;
	int nums[n];
	for (int i = 0; i < n; i++){
		cin >> nums[i];
	}
	int i = 0;
	for (int j = i; j < n; j++){
		if (nums[j] != 0){
			swap(nums[i], nums[j]);
			i++;
		}
	}
	for (int i = 0; i < n; i++){
		cout << nums[i] << " ";
	}
}