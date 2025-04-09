#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    string s;
    cin >> s;
    int k; 
    cin >> k;

    int i = 0; 
    int j = 0;
    int cnt = 0;
    int freq[26] = {0};
    int ans = -1;
    while (j < s.size()){
        freq[s[j] - 'a']++;
        int x = freq[s[j] - 'a'];
        if (x == 1) cnt++;                  // agr freq 1 h mtlb naya chharcter h isliye count bada dia
        if (cnt == k){
            int len = j - i + 1;
            ans = max(ans, len);
        }
        while (cnt > k){                      // jab tk same character bahar hoga ...krte raho
            i++;
            freq[s[i] - 'a']--;
            int y = freq[s[i] - 'a'];
            if (y == 0){
                cnt--;
            }
        }
        j++;
    }
    cout << ans << endl;
}