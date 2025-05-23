#include<iostream>
#include<queue>
#include<functional>
using namespace std;

void printheap(priority_queue<int, vector<int>, greater<int>> h){
    while (!h.empty()){
        cout << h.top() << " ";
        h.pop();
    }
    cout << endl;
}

int main(){
    priority_queue<int, vector<int>, greater<int>> h;
    int k = 3;
    int cs = 0;

    while (1){
        int data;
        cin >> data;

        if (data == -1){
            // print the heap
            printheap(h);
        }else{
            if (h.size() == k){
                if (data > h.top()){                // maintain a heap of only top 3 elements
                    h.pop();
                    h.push(data);
                }else{
                    continue;
                }
            }else {
                h.push(data);
                cs++;
            }
        }
    }
    return 0;
}