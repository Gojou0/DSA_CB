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

Node* Cyclestart(Node* head){
    Node* slow = head;
    Node* fast = head;
    
    while (fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast){
            fast = head;
            break;
        }
    }

    while (fast != slow){
        slow = slow->next;
        fast = fast->next;
    }

    return fast;
}

Node* Breakcycle(Node* head){
    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast){
            fast = head;
            break;
        }
    }

    while (fast != slow->next){
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = nullptr;
}

int main(){
    vector<int> arr;
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    Node* head = ConvertArr2LL(arr, 4);

    // Tortoise and Hare Algo
    Node* fast = head;
    NOde* slow = head;
    
    while (fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;

        if (slow == fast) return true;
    }
    return false;

}