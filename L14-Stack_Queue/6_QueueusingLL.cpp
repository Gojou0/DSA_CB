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

class Queue{
    public:
    Node* head = NULL;

    void push(int d){
        Node* n = new Node(d);
        if (!head){
            head = n;
        }else{
            Node* temp = head;
            while (temp->next){                 // Insetion at end.....taking front at begining
                temp = temp->next;
            }
            temp->next = n;
        }
    }

    void pop(){
        if (!head){
            return;
        }else if (!head->next){             
            delete head;
            head = NULL;
            return;
        }else{
            Node* temp = head;                          // deleting front of queue
            head = head->next;
            delete temp;
        }
    }

    int front(){
        return head->data;
    }

    bool empty(){
        return head == NULL;
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