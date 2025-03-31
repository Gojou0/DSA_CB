#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n; 
	cin >> n; 
	int a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	int target;
	cin >> target;
	sort(a, a+n);
	for (int i = 0; i < n; i++){
		if (i > 0 && a[i] == a[i-1]) continue;
		int j = i + 1;
		int k = n - 1;
		while (j < k){
			int sum = a[i] + a[j] + a[k];
			if (target == sum) {
				cout << a[i] << ", " << a[j] << " and " << a[k] << endl;
				j++;
				k--;
				while (j < k && a[j] == a[j-1]) j++;
				while (j < k && a[k] == a[k+1]) k--;
			}else if (target < sum){
				k--;
			}else{
				j++;
			}
		}
	}
	return 0;
}