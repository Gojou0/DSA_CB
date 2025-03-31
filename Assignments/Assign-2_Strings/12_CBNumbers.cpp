#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> cbPrimes;
void CInitialise(){
    cbPrimes.push_back(2);
    cbPrimes.push_back(3);
    cbPrimes.push_back(5);
    cbPrimes.push_back(7);
    cbPrimes.push_back(11);
    cbPrimes.push_back(13);
    cbPrimes.push_back(17);
    cbPrimes.push_back(19);
    cbPrimes.push_back(23);
    cbPrimes.push_back(29);
}

bool isCBNumber(long long num) {
    if (num == 0 || num == 1) return false;

    for (int i = 0; i < cbPrimes.size(); i++) {
        if (num == cbPrimes[i]) return true;  
    }

    for (int i = 0; i < cbPrimes.size(); i++) {
        if (num % cbPrimes[i] == 0) return false; 
    }

    return true;
}

int main(){
    CInitialise();
    int n;
    cin >> n;
    string s;
    cin >> s;
    int c = 0;
    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            string ans;
            for (int k = i; k <= j; k++){
                ans += s[k];
            }
            long long a = stoi(ans);
            if (isCBNumber(a)) c++;
        }
    }
    cout << c << endl;

    return 0;
}