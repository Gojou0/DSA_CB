#include<iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		int a[n];
		int b[m];
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		for (int i = 0; i < m; i++){
			cin >> b[i];
		}
		int i = 0;
		int j = 0;
		int suma = 0;
		int sumb = 0;
		int totalsum = 0;
		while (i < n && j < m){
			if (a[i] < b[j]){
				suma += a[i];
				i++;
			}else if (a[i] > b[j]){
				sumb += b[j];
				j++;
			}else{
				totalsum += max(suma,sumb) + a[i];
				suma = 0;
				sumb = 0;
				i++;
				j++;
			}
		}
		while (i < n) suma += a[i++];
		while (j < m) sumb += b[j++];
		totalsum += max(suma, sumb);
		cout << totalsum << endl;
	}
	return 0;
}