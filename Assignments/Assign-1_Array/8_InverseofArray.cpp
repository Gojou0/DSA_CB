#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	for (int i = 0; i < n; i++){
		a[a[i] % n] = a[a[i] % n] + i * n;              // original value -> a[i] % n .... jo chahiye value -> new value / n
	}
	for (int i = 0; i < n; i++){
		a[i] = a[i] / n;
		cout << a[i] << " ";
	}
	
	return 0;
}