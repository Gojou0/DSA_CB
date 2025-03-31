#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    int i = 0;
    int j = n-1;
    bool flag = true;
    while (i < j){
        if (s[i] != s[j]){
            flag = false;
            break;
        }
        i++;
        j--;
    }
    if (flag == false){
        cout << "false" << endl;
    }else{
        cout << "true" << endl;
    }

    return 0;
}