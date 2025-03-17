#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int items[n];
	for (int i = 0; i < n; i++){
		cin >> items[i];
	}
	int q;
	while(q--){
		int a, k;
		cin >> a >> k;
		int c = 0;
		for (int i = 0; i < n; i++){
			if (a % items[i] == 0){
				c++;
			}
		}
		if (c >= k) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}