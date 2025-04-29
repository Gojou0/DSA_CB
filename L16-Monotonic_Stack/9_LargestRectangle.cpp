#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> Nse(vector<int> &arr){
    int n = arr.size();
    vector<int> nse(n,0);
    stack<int> s;
    for (int i = n-1; i >= 0; i--){
        while (!s.empty() && arr[s.top()] >= arr[i]){           // top contains index so check it with array 
            s.pop();
        }
        nse[i] = s.empty() ? n : s.top();           // store n (n-1 ke baad aata h) as index if stack is empty
        s.push(i);
    }

    return nse;
}

vector<int> Pse(vector<int> &arr){
    int n = arr.size();
    vector<int> pse(n,0);
    stack<int> s;
    for (int i = 0; i < n; i++){
        while (!s.empty() && arr[s.top()] >= arr[i]){           
            s.pop();
        }
        pse[i] = s.empty() ? -1 : s.top();             // store -1 (0 se pehle aata h) as index if stack is empty
        s.push(i);
    }

    return pse;
}

int LR(vector<int> &arr){
    int ans = 0;
    vector<int> nse = Nse(arr);
    vector<int> pse = Pse(arr);
    for (int i = 0; i < arr.size(); i++){
        int area = arr[i] * (nse[i] - pse[i] - 1);
        ans = max(ans, area);
    }
    return ans;
}

// Without precomputation
// Finding Nse and Pse in one go
int LRO(vector<int> &arr){
    int ans = 0;
    stack<int> st;
    for (int i = 0; i < arr.size(); i++){
        while (!st.empty() && arr[st.top()] >= arr[i]){
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

int main(){
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(2);
    arr.push_back(3);

    // int ans = LR(arr);
    int ans = LRO(arr);
    cout << ans << endl;
}