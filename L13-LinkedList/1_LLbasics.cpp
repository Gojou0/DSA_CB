#include <iostream>
#include <vector>
using namespace std;

// Self Defining Datatype for node
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

Node* ConvertArr2LL(vector<int> &arr, int n){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < n; i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int lengthofLL(Node* head){
    int n = 0;
    Node* temp = head;
    while (temp != nullptr){
        temp = temp->next;
        n++;
    }
    return n;
}

bool Search(Node* head, int key){
    Node* temp = head;
    while (temp){
        if (temp->data == key){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

Node* ReverseLL(Node* head){
    Node* temp = head;
    Node* prev = NULL;
    while (temp){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

int main(){
    vector<int> arr;
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    Node* head = ConvertArr2LL(arr, 4);
    cout << head->data << endl;                 // arrow operator is used with pointers to print data of node which it is pointing
    cout << head << endl;                   // head is a pointer to first node 
    cout << (*head).data << endl;               // works same as arrow operator ...but we derefrence it first to get the node which it is pointing

    // LL traversal
    Node* temp = head;
    while (temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // finding length
    int length = lengthofLL(head);
    cout << length << endl;

    // Searching in LL
    int key = 3;
    cout << Search(head,key) << endl;

    // Reverse LL
    head = ReverseLL(head);
    
    temp = head;
    while (temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

}