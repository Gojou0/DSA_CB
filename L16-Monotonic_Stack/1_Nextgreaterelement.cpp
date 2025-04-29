// MONOTONIC STACK -> stack having specific order
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> NGE(vector<int> &arr){
    stack<int> s;
    int n = arr.size();
    vector<int> ans(n,0);
    for (int i = n-1; i >= 0; i--){
        if (s.empty()){
            ans[i] = -1;
            s.push(arr[i]);
        }else{
            if (arr[i] < s.top()){                  // if element encounter is smaller than top of the stack then top is its answer
                ans[i] = s.top();
                s.push(arr[i]);
            }else{                              // or else pop krte jao jbkt top pr value badi na aajaye encountered element se
                while (!s.empty() && arr[i] >= s.top()){            
                    s.pop();
                }
                if (s.empty()){                 // agr pop krte krte empty ho gya stack mtln no answer for that element
                    ans[i] = -1;
                }else{
                    ans[i] = s.top();
                }
                s.push(arr[i]);
            }
        }
    }

    return ans;
}

int main(){
    vector<int> arr;
    arr.push_back(4);
    arr.push_back(12);
    arr.push_back(5);
    arr.push_back(3);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(5);
    arr.push_back(3);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(4);
    arr.push_back(6);

    vector<int> nge = NGE(arr);

    for (int i = 0; i < nge.size(); i++){
        cout << nge[i] << " ";
    }
    cout << endl;
}