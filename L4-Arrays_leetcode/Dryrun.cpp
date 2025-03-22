#include<iostream>
using namespace std;

int main() {
	int x = 10;
	int* ptr = &x;
	int* exe = ptr;
	cout << *ptr << " " << exe << endl;
}