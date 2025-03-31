#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        string ans[n];
        for (int i = 0; i < n; i++){
            int x;
            cin >> x;
            ans[i] = to_string(x);
        }

        sort(ans, ans + n, [](string &a, string &b){
            return a+b > b+a;
        });

        string answer;

        for (int i = 0; i < n; i++){
            answer += ans[i];
        }

        if (answer[0] == '0'){
            cout << 0 << endl;
        }else{
            cout << answer << endl;
        }
    }
}