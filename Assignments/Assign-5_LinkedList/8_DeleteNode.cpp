#include <iostream>
#include <vector>
#include <climits>
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

Node* Delete(Node* head){
    head = ReverseLL(head);
    Node* temp = head;
    int ans = INT_MIN;
    Node* answer = new Node(0);
    Node* prev = answer;
    while (temp){
        if (temp->data >= ans){
            prev->next = temp;
            prev = prev->next;
            ans = temp->data;
        }
        temp = temp->next;
    }
    prev->next = nullptr;

    return ReverseLL(answer->next);
}

int main(){
    int n; 
    cin >> n;
    vector<int> arr(n, 0); 
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    Node* head = ConvertArr2LL(arr, n);

    head = Delete(head);

    Node* temp = head;
    while (temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}