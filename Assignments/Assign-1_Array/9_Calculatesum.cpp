#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i< n; i++){
		cin >> a[i];
	}
	int q;
	cin >> q;
	int qu[q];
	for (int i = 0; i< q; i++){
		cin >> qu[i];
	}
	int ans[n];
	for (int i = 0; i < q; i++){
		for (int j = 0; j < n; j++){
			ans[j] = a[j] + a[(j - qu[i] + n) % n];
		}
		for (int k = 0; k < n; k++){
			a[k] = ans[k];
		}
	}
	int sum = 0;
	for (int i = 0; i < n; i++){
		sum += a[i];
	}
	cout << sum % (1000000000 + 7) << endl;
}