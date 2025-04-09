#include<iostream>
#include<string>
#include<vector>
using namespace std;

int c = 0;
string Replace(string s,int i = 0){
    if (s.size() == 0){
        return "";
    }

    if (i == s.size()){
        return s;
    }

    if (s.substr(i,2) == "hi"){
		c++;
        string baki = s.substr(i+2);
        return s.substr(0,i ) + "bye" + Replace(baki);
    }
    return Replace(s, i+1);
}

string Remove(string s,int i = 0){
    if (s.size() == 0){
        return "";
    }

    if (i == s.size()){
        return s;
    }

    if (s.substr(i,2) == "hi"){
        string baki = s.substr(i+2);
        return s.substr(0,i ) + Remove(baki);
    }
    return Remove(s, i+1);
}

int main(){
    string s;
	cin >> s;

	string a = Replace(s);
	cout << c << endl;
	cout << Remove(s) << endl;
	cout << a << endl;
}