#include<iostream>
#include<queue>
using namespace std;

class Stack {
    public:
    queue <int> q;
    void Push(int x) {
        int s = q.size();
        q.push(x);
        for (int i = 0; i < s; i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int Pop() {
        int n = q.front();
        q.pop();
        return n;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

int main(){
    Stack s;
    for(int i = 1; i < 5; i++){
        s.Push(i);
    }

    while (!s.empty()){
        cout << s.top() << " ";
        s.Pop();
    }
    cout<< endl;
}