#include<iostream>
using namespace std;
int main() {
	int n; 
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	int i = 0;
	for (int j = i; j < n; j++){
		if (a[j] == 0){
			swap(a[j], a[i]);
			i++;
		}
	}
	for (int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
 	return 0;
}