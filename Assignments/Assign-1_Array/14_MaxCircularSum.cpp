#include<iostream>
#include <climits>
#include <algorithm>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		int ps[n];
		ps[0] = a[0];
        for(int i = 1; i < n; i++){
        	ps[i] = ps[i-1] + a[i];
    	}

    	//Min Sum Algo
		int sum = 0;
		int ans = INT_MAX;
    	for (int i = 0; i < n; i++){
        	for (int j = i; j < n; j++){
            	sum = ps[j] - (i-1 >= 0 ? ps[i-1] : 0);
            	ans = min(ans,sum);  
        	}
    	}
		sum = 0;
		int c_sum = ps[n-1] - ans;
		int ans_1 = INT_MIN;
		for (int i = 0; i < n; i++){
        	for (int j = i; j < n; j++){
            	sum = ps[j] - (i-1 >= 0 ? ps[i-1] : 0);
            	ans_1 = max(ans_1,sum);  
        	}
    	}
		if (c_sum != 0){
			cout << max(c_sum, ans_1) << endl;
		}else{
			cout << ans_1 << endl;
		}
	}
	return 0;
}