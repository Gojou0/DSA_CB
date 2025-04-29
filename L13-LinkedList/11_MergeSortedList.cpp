#include<iostream>
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

Node* Merge(Node* head1, Node* head2){
    if (!head1) return head2;
    if (!head2) return head1;

    Node* head;
    if (head1->data < head2->data){
        head = head1;
        head->next = Merge(head1->next, head2);             // pehla element mene check krke kr lia ..ab baki recursion krlega
    }else{
        head = head2;
        head->next = Merge(head1, head2->next);
    }
    return head;
}

int main(){
    vector<int> arr;
    arr.push_back(0);
    arr.push_back(2);
    arr.push_back(4);
    arr.push_back(6);
    vector<int> arr1;
    arr1.push_back(1);
    arr1.push_back(3);
    arr1.push_back(5);
    arr1.push_back(7);
    Node* head1 = ConvertArr2LL(arr, 4);
    Node* head2 = ConvertArr2LL(arr1, 4);

    Node* head = Merge(head1, head2);

    Node* temp = head;
    while (temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

}