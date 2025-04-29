#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int LRO(vector<int> &arr){
    int ans = 0;
    stack<int> st;
    for (int i = 0; i < arr.size(); i++){
        while (!st.empty() && arr[st.top()] > arr[i]){
            int element = st.top();                     // use element at top as element to find area
            st.pop();
            int nse = i;            // value next to element is nse as it is smaller
            int pse = st.empty() ? -1 : st.top();                   // value previous to stack top will be pse
            int area = arr[element] * (nse - pse - 1);
            ans = max(ans, area);
        }
        st.push(i);
    }

    while (!st.empty()){            // if stack is leftover...means element having no next smaller is there
        int nse = arr.size();               // therefore, nse will be n
        int element = st.top();                 // element will be top of stack
        st.pop();
        int pse = st.empty() ? -1 : st.top();               // and pse will be previous to stack top
        int area = arr[element] * (nse - pse - 1);
        ans = max(ans, area);
    }

    return ans;
}

int MR(vector<vector<char> > &arr){
    int n = arr.size();
    int m = arr[0].size();
    vector<vector<int> > ps(n, vector<int> (m,0));
    for (int j = 0; j < m; j++){
        int sum = 0;
        for (int i = 0; i < n; i++){                    
            sum += (arr[i][j] - '0');               // use prefix sum concept to get height of histogram summe up for each row
            if (arr[i][j] == '0') sum = 0;
            ps[i][j] = sum;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++){
        ans = max(ans, LRO(ps[i]));             // use Largest reactangle concept for each prefix sum row and find max area
    }

    return ans;
}

int main(){
    vector<vector<char> > arr;
    arr.push_back({'1','0','1','0','0'});
    arr.push_back({'1','0','1','1','1'});
    arr.push_back({'1','1','1','1','1'});
    arr.push_back({'1','0','0','1','0'});

    int ans = MR(arr);
    cout << ans << endl;
}