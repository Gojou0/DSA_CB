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

Node* kthfromlast(Node* head, int k){
    Node* slow = head;
    Node* fast = head;
    int c = 0;
    while (c < k){
        fast = fast->next;
        c++;
    }

    while (fast){
        fast = fast->next;
        slow = slow->next;
    }

    return slow;
}

int main(){
    vector<int> arr;
    arr.push_back(0);
    arr.push_back(5);
    arr.push_back(4);
    arr.push_back(3);
    arr.push_back(1);
    arr.push_back(7);
    arr.push_back(9);
    Node* head = ConvertArr2LL(arr, 7);

    Node* ans = kthfromlast(head, 2);
    cout << ans->data << endl;
}