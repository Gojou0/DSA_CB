#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int nums[n];
	for (int i = 0; i < n; i++){
		cin >> nums[i];
	}
	int target;
	cin >> target;
	int s = 0;
	int e = n - 1;
	bool flag = false;
	while (s <= e){
		int mid = s + (e - s) / 2;
		if (nums[mid] == target) {
			cout << mid << endl; 
			flag = true;
			break;
		}else if (nums[mid] > target){
			e = mid - 1;
		}else{
			s = mid + 1;
		}
	}
	if (flag == false){
		cout << "-1" << endl;
	}
	
	return 0;
}