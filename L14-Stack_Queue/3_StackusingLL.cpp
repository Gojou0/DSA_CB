#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    // Calling Constructor
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
    }
};


class Stack{
    public:
    Node* head = NULL;

    void push(int d){
        Node* n = new Node(d);
        if (head == NULL){
            head = n;
        }else{
            n->next = head;             // Insertion at beginning.... taking top at beginning
            head = n;
        }
    }

    void pop(){
        if (!head){
            return;
        }else if(head->next == NULL){
            delete head;
            head = NULL;
            return;
        }else{
            Node* temp = head;                  // deleting top
            head = head->next;
            delete temp;
        }
    }

    int top(){
        return head->data;
    }

    bool empty(){
        return head == NULL;
    }

};

int main(){
    Stack s;
    for(int i = 1; i < 5; i++){
        s.push(i);
    }

    while (!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout<< endl;
}