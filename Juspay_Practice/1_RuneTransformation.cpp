#include<iostream>
#include<string>
using namespace std;

int Score(string s){
    int ans = 0;
    int segx = 0, segy = 0, cx = INT_MAX;
    bool flag = false;
    for (int i = 0; i < s.size()-1; i++){
        if (s[i] == 'X'){
            int cnt2 = 0;
            while (i < s.size() && s[i] == 'X'){
                cnt2++;
                i++;
            }
            cx = min(cx, cnt2);
            i--;
            segx++;
        }else{
            int cnt = 0;
            while (i < s.size() && s[i] == 'Y'){
                cnt++;
                i++;
            }
            i--;
            if (cnt > 1) flag = true;
            segy++;
        }
    }

    if (segx <= segy){                  // agr x seg or y seg ke count se chota ya equal h....toh saare x covert ho jaenge
        for (auto i : s){
            if (i == 'X'){
                ans++;
            }
        }
        return ans;
    }else{
        if (flag == true){              // agr x segs jyada h y seg se toh....agr kisi bhi y seg me y ka count >1 hua to bhi saare x convert ho jaenge
            for (auto i : s){
                if (i == 'X'){
                    ans++;
                }
            }
            return ans;
        }else{                  // agr ek bhi y seg me y count > 1 nhi h ..toh sare x except xseg which has less count of x nhi honge
            for (auto i : s){
                if (i == 'X'){
                    ans++;
                }
            }
            return ans - cx;
        }
    }
}

int main(){
    string s;
    cin >> s;
    cout << Score(s) << endl;
}