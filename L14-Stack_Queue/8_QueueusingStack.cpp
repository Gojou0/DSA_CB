#include<iostream>
#include<stack>
using namespace std;

class Queue {
    public:
    stack <int> s, help;
    
    void Push(int x) {
        while (!s.empty()){
            help.push(s.top());
            s.pop();
        }

        s.push(x);
        while (!help.empty()){
            s.push(help.top());
            help.pop();
        }
    }
    
    int Pop() {
        int n = s.top();
        s.pop();
        return n;
    }
    
    int front() {
        return s.top();
    }
    
    bool empty() {
        return s.empty();
    }
};

int main(){
    Queue q;

    for (int i = 1; i < 6; i++){
        q.Push(i);
    }

    while (!q.empty()){
        cout << q.front() << " ";
        q.Pop();
    }
    cout << endl;
}