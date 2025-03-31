#include<iostream>
#include<math.h>
using namespace std;

int size(int n){
	int c = 0;
	while (n > 0){
		n /= 10;
		c++;
	}
	return c;
}

bool Armstrong(int n){
	int s = size(n);
	int sum = 0;
	int temp = n;
	while(temp > 0){
		int dig = temp % 10;
		sum += pow(dig,s);
		temp /= 10;
	}
	return sum == n;
}
int main() {
	int n; 
	cin >> n;
	if (Armstrong(n)){
		cout << "true" << endl;
	}else{
		cout << "false" << endl;
	}
}