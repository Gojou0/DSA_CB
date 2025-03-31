#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	int leftmax[n];
	leftmax[0] = 0;
	for (int i = 1; i < n; i++){
		leftmax[i] = max(leftmax[i-1], a[i-1]);
	}
	int rightmax[n];
	rightmax[n-1] = 0;
	for (int i = n - 2; i >= 0; i--){
		rightmax[i] = max(rightmax[i+1], a[i+1]);
	}

	int sum = 0;
	for (int i = 0; i < n; i++){
		sum += (min(leftmax[i], rightmax[i]) - a[i] > 0) ? min(leftmax[i], rightmax[i]) - a[i] : 0;
	}
	cout << sum << endl;
	return 0;
}