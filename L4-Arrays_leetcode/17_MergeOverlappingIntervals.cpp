#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int a[4][2] = {{1,3},{2,6},{8,10},{15,18}};
    int n = 4;
    sort(a,a+n);
    vector<vector<int>> ans;
    for (int i = 0; i< n; i++){
        int first = a[i][0];
        int second = a[i][1];
        if (!ans.empty() && ans.back()[1] >= second){                   // to omit intervals which we have combined
            continue;
        }
        for (int j = i + 1; j< n; j++){     
            if (a[j][0] <= second){                                     // agr pehle interval ka second uske agle k first se bad hua to
                second = max(second, a[j][1]);                          // combine kr skte h or dono ke second m jo max h wo le lenge
            }else{
                break;
            }
        }
        ans.push_back({first, second});
    }

    // OPTIMAL APPROACH

    // for (int i = 0; i < n; i++){
    //     if (ans.empty() || ans.back()[1] < a[i][0]){
    //         ans.push_back(a[i]);
    //     }else{
    //         ans.back()[1] = max(ans.back()[1], a[i][1]);
    //     }
    // }
    // return ans;
}