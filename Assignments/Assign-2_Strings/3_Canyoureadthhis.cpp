#include<iostream>
#include<string>
#include<cctype>
using namespace std;

int main(){
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++){
        if (isupper(s[i]) && i > 0){
            cout << endl;
        }
        cout << s[i];
    }

    return 0;
}