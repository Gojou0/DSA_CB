#include<iostream>
using namespace std;

int main () {
	int n;
	cin >> n;
	int ans = 0;
	while (n > 0){
		if (n % 10 != 0){
			ans = ans * 10 + n % 10;
		}else{
			ans = ans * 10 + 5;
		}
		n = n / 10;
	}
	int answer = 0;
	while (ans > 0){
		answer = answer * 10 + ans % 10;
		ans /= 10;
	}
	cout << answer << endl;

	return 0;
}