#include<iostream>
using namespace std;
int sumofdigits(int n){
	int sum = 0;
	while (n > 0){
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int main() {
	int n;
	cin >> n;
	int sum1 = sumofdigits(n);

	int temp = n;
	int sum2 = 0;
	while (temp % 2 == 0){
		sum2 += 2;
		temp /= 2;
	}

	for (int i = 3; i <= temp; i += 2){
		while (temp % i == 0){
			sum2 += sumofdigits(i);
			temp /= i;
		}
	}

	if (sum1 == sum2){
		cout << "1" << endl;
	}else{
		cout << "0" << endl;
	}
	return 0;
}