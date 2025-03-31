#include <iostream>
#include <string>
using namespace std;

bool isVowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int main() {
    string s;
    cin >> s;

    int n = s.size();
    int maxLen = 0, currLen = 0;

    for (int i = 0; i < n; i++) {
        if (isVowel(s[i])) {
            currLen++;
            maxLen = max(maxLen, currLen);
        } else {
            currLen = 0;
        }
    }

    cout << maxLen << endl;

    return 0;
}
