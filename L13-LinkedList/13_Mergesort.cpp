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

Node* Middle(Node* head){
    Node* slow = head;
    Node* fast = head->next;
    
    while (fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node* Merge(Node* head1, Node* head2){
    if (!head1) return head2;
    if (!head2) return head1;

    Node* head;
    if (head1->data < head2->data){
        head = head1;
        head->next = Merge(head1->next, head2);             
    }else{
        head = head2;
        head->next = Merge(head1, head2->next);
    }
    return head;
}

Node* MergeSort(Node* head){
    if (!head || !(head->next)) return head;

    Node* m = Middle(head);
    Node* left = head;
    Node* right = m->next;
    m->next = nullptr;

    left = MergeSort(left);
    right = MergeSort(right);

    return Merge(left, right);
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

    Node* temp = head;
    while (temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    head = MergeSort(head);

    temp = head;
    while (temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}