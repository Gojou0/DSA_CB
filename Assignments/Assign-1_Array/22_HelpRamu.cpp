#include<iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--){
		int costs[4];
		for (int i = 0; i < 4; i++){
			cin >> costs[i];
		}
		int r, c;
		cin >> r >> c;
		int ri[r];
		for (int i = 0; i < r; i++){
			cin >> ri[i];
		}
		int ci[c];
		for (int i = 0; i < c; i++){
			cin >> ci[i];
		}
		int tr, tc;
		int minr = 0;
		for (int i = 0; i < r; i++){
			minr += min((ri[i] * costs[0]), costs[1]);
		}
		tr = min(minr, costs[2]);
		int minc = 0;
		for (int i = 0; i < c; i++){
			minc += min((ci[i] * costs[0]), costs[1]);
		}
		tc = min(minc, costs[2]);
		int total_cost = min((tr + tc), costs[3]);
		cout << total_cost << endl;
	}
	return 0;
}
