#include<iostream>
#include<string>
using namespace std;

string Rek(string &s, int k){
    string ans;                 // use string stl as stack
    for (auto i : s){
        while (!ans.empty() && k > 0 && ans.back() - '0' > i - '0'){            // agr k bacha h or value choti stack top se...to pop krte rho
            ans.pop_back();
            k--;
        }
        ans.push_back(i);
    }

    while (k > 0){              // agr abhi bhi k bacha h to pop krte rho jb tk k 0 na ho jaye
        ans.pop_back();
        k--;
    }
    if (ans.empty()) return "0";            // in the end agr stack khali bacha ...to 0 answer h
    else{
        int i = 0;                  
        while (i < ans.size() && ans[i] == '0') i++;        // deleting leading zeroes
        ans = ans.substr(i);
        if (ans.empty()) return "0";
        else return ans;
    }
}

int main(){
    string s;
    cin >> s;
    int k;
    cin >> k;
    string ans = Rek(s, k);
    cout << ans << endl;
}