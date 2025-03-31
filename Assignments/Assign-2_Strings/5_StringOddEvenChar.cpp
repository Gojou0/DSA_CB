#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++){
        if (i%2 == 0){
            int a = (int)(s[i]) + 1;
            s[i] = (char)a;
        }else{
            int b = (int)(s[i]) - 1;
            s[i] = (char)b;
        }
    }
    cout << s << endl;
}