#include<iostream>
#include<string>
#include<vector>
using namespace std;

string Replace(string s,int i = 0){
    if (s.size() == 0){
        return "";
    }

    if (i == s.size()){
        return s;
    }

    if (s.substr(i,2) == "pi"){
        string baki = s.substr(i+2);
        return s.substr(0,i ) + "3.14" + Replace(baki);
    }
    return Replace(s, i+1);
}

int main(){
    int n;
    cin >> n;
    vector<string> arr;
    for (int i = 0; i < n; i++){
        string x;
        cin >> x;
        arr.push_back(x);
    }

    for (int i = 0; i < n; i++){
        cout << Replace(arr[i]) << endl;
    }

}