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

Node* DeleteHead(Node* head){
    if (head == NULL || head->next == nullptr) return NULL;
    Node* prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;
    free(prev);
    return head;
}

Node* DeleteTail(Node* head){
    if (head == NULL || head->next == nullptr) return NULL;
    Node* temp = head;
    while (temp->next->next){
        temp = temp->next;
    }
    temp->next->back = nullptr;
    temp->next = nullptr;
    delete temp->next;
    return head;
}

Node* Deletekthele(Node* head, int k){
    if (head == NULL) return NULL;
    Node* temp = head;
    int cnt = 0;
    while (temp){
        cnt++;
        if (cnt == k){
            break;
        }
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* front = temp->next;
    if (prev == NULL && front == NULL){             // mtlb ek hi element h isme
        delete temp;
        return NULL;
    }else if (prev == NULL){                    // head pr h temp
        return DeleteHead(head);
    }else if (front == NULL){                   // tail pr h tmep
        return DeleteTail(head);
    }
    prev->next = front;
    front->back = prev;
    temp->next = nullptr;
    temp->back = nullptr;
    delete temp;
    return head;        
}

Node* Deletenode(Node* head, int val){
    Node* temp = head;
    while (temp){
        if (temp->data == val){
            break;
        }
        temp = temp->next;
    }
    Node* front = temp->next;
    Node* prev = temp->back;
    if (front == NULL){
        return DeleteTail(head);
    }
    prev->next = front;
    front->back = prev;
    temp->next = nullptr;
    temp->back = nullptr;
    delete temp;
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

    Node* head = ConvertToDLL(arr);

    // Deleting head
    head = DeleteHead(head);

    // Deleting tail
    head = DeleteTail(head);

    // Deleting kth element
    head = Deletekthele(head, 5);

    // Deleting by Node value
    head = Deletenode(head, 7);

    Node* temp = head;
    while (temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}