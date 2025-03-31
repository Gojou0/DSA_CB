#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;

    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* ConvertToDLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for (int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        prev->next = temp;
        temp->back = prev;
        prev = prev->next;
    }
    return head;
}

Node* Inserthead(Node* head, int val){
    Node* val1 = new Node(val);
    if (head == NULL) return val1;
    val1->back = nullptr;
    val1->next = head;
    head->back = val1;
    return val1;
}

Node* Inserttail(Node* head, int val){
    Node* val1 = new Node(val);
    if (head == NULL) return val1;
    if (head->next == NULL) return Inserthead(head, val);
    Node* temp = head;
    while (temp->next){
        temp = temp->next;
    }
    Node* prev = temp->back;
    prev->next = val1;
    val1->back = prev;
    val1->next = temp;
    temp->back = val1;
    return head;
}

Node* Insertatkth(Node* head, int val, int k){
    Node* val1 = new Node(val);
    if (head == NULL) return val1;
    Node* temp = head;
    int cnt = 0;
    while (temp){
        cnt++;
        if (cnt == k){
            break;
        }
        temp = temp->next;
    }
    Node* front = temp->next;
    Node* prev = temp->back;
    if (front == NULL && prev == NULL){
        return Inserthead(head, val);
    }else if (front == NULL){
        return Inserthead(head, val);
    }else if (prev == NULL){
        return Inserttail(head, val);
    }
    prev->next = val1;
    val1->back = prev;
    val1->next = temp;
    temp->back = val1;
    return head;
}

void InsertNode(Node* node, int val){                   // no change in head
    Node* val1 = new Node(val);
    Node* prev = node->back;
    prev->next = val1;
    val1->back = prev;
    val1->next = node;
    node->back = val1;
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

    Node* head = ConvertToDLL(arr);

    // Insert before head
    head = Inserthead(head, -1);

    // Insert before tail
    head = Inserttail(head, 70);

    // Insert at kth pos
    head = Insertatkth(head, 10, 6);

    // Insert before any node except head
    InsertNode(head->next->next->next, 5);

    Node* temp = head;
    while (temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}