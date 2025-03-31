#include<iostream>
using namespace std;
int reverseint(int n){
	int ans = 0;
	while (n > 0){
		ans = ans * 10 + n % 10;
		n = n / 10;
	}
	return ans;
}
int size(int n){
	int c = 0;
	while (n > 0){
		n /= 10;
		c++;
	}
	return c;
}
int main() {
	int n;
	cin >> n;
	int s = size(n);
	int a[s];
	for (int i = 1; i <= s; i++){
		a[i] = n % 10;
		n = n / 10;
	}
	int ans[s];
	for (int i = 1; i <= s; i++){
		ans[a[i]] = i;
	}
	int num = 0;
	for (int i = 1; i <= s; i++){
		num = num * 10 + ans[i];
	}
	int nums = reverseint(num);
	cout << nums << endl;

	return 0;
}