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

Node* kthfromlast(Node* head, int k){
    Node* slow = head;
    Node* fast = head;
    int c = 0;
    while (c < k){
        fast = fast->next;
        c++;
    }

    while (fast){
        fast = fast->next;
        slow = slow->next;
    }

    return slow;
}

int main(){
    vector<int> arr;
	int n = 0;
    while (true){
		int x;
		cin >> x;
		if (x == -1) break;
 		arr.push_back(x);
		n++;
	}
	int k;
	cin >> k;
    Node* head = ConvertArr2LL(arr, n);

    Node* ans = kthfromlast(head, k);
    cout << ans->data << endl;
}