#include<iostream>
using namespace std;

int main () {
	int n;
	cin >> n;
	int a[n] = {0};
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	int element;
	int cancel = 0;
	for (int i = 0; i < n; i++){
		if (cancel == 0){
			element = a[i];
		}
		if (a[i] == element){
			cancel++;
		}else{
			cancel--;
		}
	}

	int c = 0;
	for (int i = 0; i < n; i++){
		if (a[i] == element){
			c++;
		}
	}

	if (c > n /2){
		cout << element << endl;
	}else{
		cout << "-1" << endl;
	}
	return 0;
}