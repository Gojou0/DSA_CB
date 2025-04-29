#include<iostream>
#include<vector>
using namespace std;

class Queue{
    public:
    vector<int> q;

    void push(int d){
        q.push_back(d);
    }

    void pop(){
        reverse(q.begin(), q.end());
        q.pop_back();
        reverse(q.begin(), q.end());
    }

    int front(){
        return q[0];
    }

    bool empty(){
        return q.size() == 0;
    }
};

int main(){
    Queue q;

    for (int i = 1; i < 6; i++){
        q.push(i);
    }

    while (!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}