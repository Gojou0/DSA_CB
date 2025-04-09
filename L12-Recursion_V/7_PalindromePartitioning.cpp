#include<iostream>
#include<string>
#include<string>
using namespace std;

vector<vector<string> > answer;

bool ispalindrome(string s){
    int i = 0; 
    int j = s.size() - 1;
    while (i <= j){
        if(s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

void Solve(string s, vector<string> ans){
    if (s.size() == 0){
        answer.push_back(ans);
        return;
    }

    for (int i = 1; i <= s.size(); i++){
        string temp = s.substr(0,i);
        if (ispalindrome(temp)){
            ans.push_back(temp);
            Solve(s.substr(i), ans);
            ans.pop_back();
        }
    }
}

int main(){
    string s;
    cin >> s;
    vector<string> ans;
    Solve(s, ans);
    for (int i = 0; i < answer.size(); i++){
        for (int j = 0; j < answer[i].size(); j++){
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }
}