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

bool Search(Node* head, int val){
    Node* temp = head;
    while (temp){
        if (temp->data == val){
            return true;
        }
        temp = temp->next;
    }
    return false;
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

    // treversing a DLL
    Node* temp = head;
    while (temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    cout << Search(head, 11) << endl;

    return 0;
}