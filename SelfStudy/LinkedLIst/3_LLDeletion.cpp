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

Node* Deletehead(Node* head){
    if (head == NULL) return head;
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

Node* Deletetail(Node* head){
    if (head == NULL || head->next == nullptr){
        return NULL;
    }
    Node* temp = head;
    while (temp->next->next){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = nullptr;
    return head;
}

Node* Delete(Node* head, int k){    
    if(head == NULL) return head;    
    if (k == 1){                    // for head to delete
        Node* temp = head;      
        head = head->next;
        free(temp);
        return head;
    }
    Node* temp = head;
    int cnt = 0;
    Node* prev = NULL;
    while (temp){                   // to delete at any positions including tail
        cnt++;
        if (cnt == k){
            prev->next = temp->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node* Deletevalue(Node* head, int key){
    if (head == NULL) return head;
    if (key == head->data){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node* temp = head;
    Node* prev = NULL;
    while (temp){
        if (temp->data == key){
            prev->next = temp->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
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

    // Deleting head 
    head = Deletehead(head);
    
    // Deleting tail
    head = Deletetail(head);

    // Deleting at any positions
    int k = 4;
    head = Delete(head, k);

    // Deleting based on value
    int key = 9;
    head = Deletevalue(head, key);

    Node* temp = head;
    while (temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    
    return 0;
}