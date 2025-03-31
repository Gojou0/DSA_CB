#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
int main() {
	int t; 
	cin >> t;
	while (t--){
		int n; 
		cin >> n;
		int a[n] = {0};
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		int money;
		cin >> money;
		sort(a,a+n);
		int ansi;
		int ansj;
		// int diff = INT_MAX;
		int i = 0;
		int j = n - 1;
		while (i < j){
			int sum = a[i] + a[j];
			if (money == sum){
				ansi = i;
				ansj = j;
				i++;
				j--;
				// diff = abs(a[j] - a[i]);
				while (i < j && a[i] == a[i-1]) i++;
				while (i < j && a[j] == a[j+1]) j--;
			}else if (money < sum){
				j--;
			}else{
				i++;
			}
		}
		if (a[ansi] < a[ansj]){
			cout << "Deepak should buy roses whose prices are " << a[ansi] << " and " << a[ansj] << "." << endl;
		}else{
			cout << "Deepak should buy roses whose prices are " << a[ansj] << " and " << a[ansi] << "." << endl;
		}
	}
	return 0;
}