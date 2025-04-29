#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* Insertatstart(Node* head, int key){
    Node* key1 = new Node(key);
    key1->next = head;
    return key1;
}

Node* Insertatend(Node* head, int key){
    Node* key1 = new Node(key);
    if (head == NULL) return key1;
    Node* temp = head;
    while (temp->next){
        temp = temp->next;
    }
    temp->next = key1;
    return head;
}

Node* Insertatpos(Node* head, int k, int key){
    Node* key1 = new Node(key);
    if (head == NULL) return key1;
    if (k == 1){                        // insert before head
        key1->next = head;
        return key1;
    }
    Node* temp = head;
    int cnt = 0;
    while (temp){                           // insert at any position including after tail
        cnt++;
        if (cnt == k - 1){
            key1->next = temp->next;
            temp->next = key1;
            break;
        }
        temp = temp->next;
    }
    return head;
}

Node* Insertbeforeval(Node* head, int key, int val){
    Node* key1 = new Node(key);
    if (head == NULL) return key1;
    if (head->data == val){
        key1->next = head;
        return key1;
    }
    Node* temp = head;
    while (temp->next){
        if (temp->next->data == val){
            key1->next = temp->next;
            temp->next = key1;
            break;
        }
        temp = temp->next;
    }
    if (temp->next == NULL){
        cout << "NOT FOUND" << endl;
    }
    return head;
}

int main(){
    vector<int> arr;
    arr.push_back(0);
    arr.push_back(3);
    arr.push_back(7);
    arr.push_back(9);
    arr.push_back(11);
    arr.push_back(19);
    arr.push_back(71);

    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    int key = 10;

    // insert at beginning
    head = Insertatstart(head, key);

    // insert at the end
    head = Insertatend(head, key);

    // Insert at any positions
    head = Insertatpos(head, 6, key);

    // Insert before any value;
    head = Insertbeforeval(head, key, 119);

    Node* temp = head;
    while (temp){
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}