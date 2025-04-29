#include<iostream>
#include<vector>
using namespace std;

vector<int> AC(vector<int> &arr){
    vector<int> ans;                // using vector stl as stack
    int n = arr.size();
    for (int i = 0; i < n; i++){
        if (arr[i] > 0){                // -ve pehla number hua bhi to collision hoga hi nhi ..opposite jaenge dono
            ans.push_back(arr[i]);
        }else{
            while (!ans.empty() && (ans.back() > 0 && abs(arr[i]) > ans.back())){            // jbtk stack m choti value h use pop kro
                ans.pop_back();
            }
            if (!ans.empty() && ans.back() == abs(arr[i])){            // agr barabar value h to bhi pop krdo..lekin arr[i] push mat kro
                ans.pop_back();                             // equal and less alag isliye kiya taki arr[i] skip kr ske same value pr
            }else if (ans.empty() || ans.back() < 0){           // agr stack khali h ya usme hi -ve value h tbhi -ve value push kro
                ans.push_back(arr[i]);
            }
        }
    }
    return ans;
}

int main(){
    vector<int> arr;
    arr.push_back(-8);
    arr.push_back(10);
    arr.push_back(-5);

    vector<int> ans = AC(arr);

    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}