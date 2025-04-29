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

Node* Solve(Node* head){
    Node* left = NULL;
    Node* right = NULL;
    Node* l = NULL;
    Node* r = NULL;
    Node* temp = head;
    while (temp){
        Node* nex = temp->next;
        temp->next = nullptr;
        if (temp->data % 2 != 0){
            if (!left){
                left = l = temp;
            }else{
                l->next = temp;
                l = l->next;
            }
        }else{
            if (!right){
                right = r = temp;
            }else{
                r->next = temp;
                r = r->next;
            }
        }
        temp = nex;
    }
    if (l){
        l->next = right;
        return left;
    }else{
        return right;
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n,0);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    Node* head = ConvertArr2LL(arr, n);

    head = Solve(head);

    Node* temp = head;
    while (temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}