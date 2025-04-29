// MONOTONIC STACK -> stack having specific order
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> NGE2(vector<int> &arr){
    stack<int> s;
    int n = arr.size();
    vector<int> ans(n,0);
    for (int i = 2*n-1; i >= 0; i--){                       // start from 2n-1 bcoz of circular array nature
        while (!s.empty() && s.top() <= arr[i%n]){              // pop until greater element found on top
            s.pop();
        }
        if (i < n){                                         // in answer,, add only that elements having index less than n
            ans[i] = (s.empty()) ? -1 : s.top(); 
        }

        s.push(arr[i%n]);                       // push all elements in stack despite of their index
    }

    return ans;
}

int main(){
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(3);

    vector<int> nge = NGE2(arr);

    for (int i = 0; i < nge.size(); i++){
        cout << nge[i] << " ";
    }
    cout << endl;
}