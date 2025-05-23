#include<iostream>
#include<queue> // heap is priority queue inside STL
#include<functional>
using namespace std;

int main(){
    // priority_queue<int> h;  // Max heap (default)

    priority_queue<int, vector<int> , greater<int>> h;

    h.push(1);
    h.push(2);
    h.push(3);
    h.push(4);

    while (!h.empty()){
        cout << h.top() << endl;
        h.pop();
    }
}