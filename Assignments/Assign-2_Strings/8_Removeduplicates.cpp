#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    cin >> s;
    int c = 0;
    char element = s[0];
    for (int i = 1; i < s.size(); i++){
        if (s[i] == element){
            continue;
        }else{
            cout << element;
            element = s[i]; 
        }
    }
    cout << element; 
}