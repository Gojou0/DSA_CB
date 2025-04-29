#include<iostream>
#include<vector>
#include<stack>
#include<utility>
using namespace std;

stack<pair<int, int> > st;
int i = -1;

int next(int n){
    i++;
    int ans;
    while (!st.empty() && st.top().second <= n){
        st.pop();
    }
    ans = i - (st.empty() ? -1 : st.top().first);
    st.push({i, n});
    
    return ans;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        cout << next(n) << endl;
    }
}