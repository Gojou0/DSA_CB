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

Node* middle(Node* head){
    Node* slow = head;
    Node* fast = head->next;
    
    while (fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

int main(){
    vector<int> arr;
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    Node* head = ConvertArr2LL(arr, 5);

    head = middle(head);
    cout << head->data << endl; 
}