#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n; 
	cin >> n;
	int m;
	cin >> m;
	int ispresent[100005] = {0};
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		ispresent[x]++;
	}5 

	for (int i = 0; i < m; i++){
		int num;
		cin >> num;
		if (ispresent[num] > 0){
			cout << num << " ";
			ispresent[num]--;
		}
	}
	return 0;

}

