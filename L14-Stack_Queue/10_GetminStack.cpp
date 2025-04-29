#include<iostream>
#include<stack>
using namespace std;

class MinStack{
    stack<int> s;
    int mini = INT_MAX;
    public:
    void push(int d){
        if (s.empty()){
            s.push(d);
            mini = d;
        }else{
            if (d >= mini){
                s.push(d);
            }else{
                s.push(2*d - mini);                 // store modified value in stack
                mini = d;                           // and top in mini
            }
        }
    }

    void pop(){
        if (s.top() >= mini){
            s.pop();
        }else{
            mini = 2*mini - s.top();                // retrive old value from modified value  (previous value i.e d is stored in mini)
            s.pop();
        }
    }

    int getmin(){
        return mini;
    }

    int top(){
        int x = s.top();
        if (x >= mini){
            return x;
        }else{
            return mini;                    // mini has the top value in case of any value gets smaller than mini
        }
    }

    bool empty(){
        return s.empty();
    }

};

int main(){
    MinStack s;
    s.push(12);
    s.push(15);
    s.push(10);
    cout << s.getmin() << " ";
    s.pop();
    cout << s.getmin() << " ";
    cout << s.top() << " ";
    s.push(10);
    cout << s.top() << " ";
}