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

Node* Solve(Node* head, int k){
    int c = 0;
    Node* temp = head;
    while (temp){
        c++;
        temp = temp->next;
    }
    if (c < k){
        return head;
    }

    Node* temp1 = head;
    for (int i = 1; i < k; i++){
        temp1 = temp1->next;
    }

    Node* Baki = temp1->next;
    temp1->next = nullptr;
    head = ReverseLL(head);
    temp1 = head;
    while (temp1->next){
        temp1 = temp1->next;
    }
    temp1->next = Solve(Baki, k);

    return head;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n,0);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    Node* head = ConvertArr2LL(arr, n);

    head = Solve(head, k);

    Node* temp = head;
    while (temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}