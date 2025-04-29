#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// i < j < k -> index k hisab se k 3rd element h
// arr[i](ai) < arr[k](ak) < arr[j](aj) -> pattern k hisab se j 3rd element hoga and bada bhi hoga..toh pehle k ki value j me aati h..and then k me jati h...j ko largest rkhne k liye

bool Solve(vector<int> &arr){
    int n = arr.size();
    int ak = INT_MIN;             // bich(ak) wala element ..abhi iski value koi isliye nhi h kyuki abhi 3rd element(aj) ki bhi nhi h...jb 3rd ki hogi tbhi to bich wale ki ho skti h
    stack<int> st;
    for (int a = n - 1; a >= 0; a--){           // ulta traversa index ki confusion ki wajah se kiya ....ulte jaenge to i to automatically kam hi hoga index me
        if (nums[i] < ak) return true;          // agr pehla(ai) element bich(ak) se chota ho gya...to last(aj) se bhi chota hi hoga.. mtlb pattern mil gya
        while (!st.empty() && st.top() < arr[a]){           // find the bump
            ak = st.top();                  // bich(ak) wale element me previous largest dalte jao....bcoz h to last(k) index ka element hi
            st.pop();
        }
        st.push(arr[a]);        // or last(aj) element(by pattern) me largest value dalte jao..kyuki pattern ke acc wo sabse largest hona chahiye
    }
}

int main(){
    vector<int> arr;
    arr.push_back(3);
    arr.push_back(1);
    arr.push_back(4);
    arr.push_back(2);

    cout << Solve(arr) << endl;
} 