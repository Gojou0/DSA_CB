#include<iostream>
#include<string>
using namespace std;

void BS(string s, int i = 0){
    if (i == s.size()){
        cout << s << " ";
        return;
    }

    if (s[i] == '?'){
        string temp1 = s.substr(0,i) + '0' + s.substr(i+1);
        string temp2 = s.substr(0,i) + '1' + s.substr(i+1);
        BS(temp1);
        BS(temp2);
    }else{
        BS(s, i+1);
    }
}

int main(){
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        BS(s);
    }
}