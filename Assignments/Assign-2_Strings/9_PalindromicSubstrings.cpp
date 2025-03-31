#include<iostream>
#include<string>
using namespace std;

bool ispalin(string s){
    int n = s.size();
    int i = 0;
    int j = n - 1;
    while (i <= j){
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

int main(){
    string s;
    cin >> s;
    int c = 0;
    for (int i = 0; i < s.size(); i++){
        for (int j = i; j < s.size(); j++){
            string sub;
            for (int k = i; k <= j; k++){
                sub += s[k];
            }
            if (ispalin(sub)) c++;
        }
    }
    cout << c << endl;
}