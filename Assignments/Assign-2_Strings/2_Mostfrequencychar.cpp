#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

int main(){
    string s;
    cin >> s;
    unordered_map<char, int> freq;
    int c = 0;
    char ans;
    for (int i = 0; i < s.size(); i++){
        freq[s[i]]++;
        if (freq[s[i]] > c){
            c = freq[s[i]];
            ans = s[i];
        }
    }
    cout << ans << endl;

    return 0;
}