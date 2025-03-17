#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    // Brute Force Approach


    string s;
    cin >> s;
    int n = s.size();
    int m;
    cin >> m;
    vector <int> positions(m,0);
    for (int i = 0; i < m; i++){
        cin >> positions[i];
    }
    for (int i = 0; i < m; i++){
        reverse(s.begin() + (positions[i] - 1), s.begin() + (n - positions[i] + 1));
    }

    cout << s << endl;

}