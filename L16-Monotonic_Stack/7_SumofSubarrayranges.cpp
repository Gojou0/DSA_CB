#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int MOD = 1e9 + 7;

vector<int> NGE(vector<int> &arr){
    int n = arr.size();
    vector<int> nge(n,0);
    stack<int> s;
    for (int i = n-1; i >= 0; i--){
        while (!s.empty() && arr[s.top()] <= arr[i]){           // top contains index so check it with array 
            s.pop();
        }
        nge[i] = s.empty() ? n : s.top();           // store n (n-1 ke baad aata h) as index if stack is empty
        s.push(i);
    }

    return nge;
}

vector<int> PGEE(vector<int> &arr){
    int n = arr.size();
    vector<int> pgee(n,0);
    stack<int> s;
    for (int i = 0; i < n; i++){
        while (!s.empty() && arr[s.top()] < arr[i]){            // popping only smaller elements to get equal element too..
            s.pop();
        }
        pgee[i] = s.empty() ? -1 : s.top();             // store -1 (0 se pehle aata h) as index if stack is empty
        s.push(i);
    }

    return pgee;
}

vector<int> NSE(vector<int> &arr){
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

vector<int> PSEE(vector<int> &arr){
    int n = arr.size();
    vector<int> psee(n,0);
    stack<int> s;
    for (int i = 0; i < n; i++){
        while (!s.empty() && arr[s.top()] > arr[i]){            // popping only greater elements to get equal element too..
            s.pop();
        }
        psee[i] = s.empty() ? -1 : s.top();             // store -1 (0 se pehle aata h) as index if stack is empty
        s.push(i);
    }

    return psee;
}

int MaxSum(vector<int> &arr){
    int ans = 0;
    vector<int> nge = NGE(arr);         // get next greater element array containig indexes
    vector<int> pgee = PGEE(arr);       // get previous greater or equal element array containig indexes to prevent SUBARRAY REDUNDANCY

    for (int i = 0; i < arr.size(); i++){
        int rightsub = nge[i] - i;
        int leftsub = i - pgee[i];
        ans = (ans + ((1LL * leftsub * rightsub) % MOD) * arr[i]) % MOD;
    }

    return ans;
}

int MinSum(vector<int> &arr){
    int ans = 0;
    vector<int> nse = NSE(arr);         // get next smaller element array containig indexes
    vector<int> psee = PSEE(arr);       // get previous smaller or equal element array containig indexes to prevent SUBARRAY REDUNDANCY

    for (int i = 0; i < arr.size(); i++){
        int rightsub = nse[i] - i;
        int leftsub = i - psee[i];
        ans = (ans + ((1LL * leftsub * rightsub) % MOD) * arr[i]) % MOD;
    }

    return ans;
}

int SubRange(vector<int> &arr){
    int maximums = MaxSum(arr);
    int minimums = MinSum(arr);

    int ans = maximums - minimums;
    return ans;
}

int main(){
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);

    int ans = SubRange(arr);
    cout << ans << endl;
}