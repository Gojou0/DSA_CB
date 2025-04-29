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

Node* SumofLL(Node* head1, Node* head2){
	head1 = ReverseLL(head1);
    head2 = ReverseLL(head2);

    Node* result = new Node(0);
    Node* answer = result;

    Node* temp1 = head1;
    Node* temp2 = head2;
    int carry = 0;

    while (temp1 && temp2){
        Node* ans = new Node(0);
        ans->data = temp1->data + temp2->data + carry;
        carry = 0;
        if (ans->data > 9){
            carry = ans->data / 10;
            ans->data = ans->data % 10;
        }
        answer->next = ans;
        answer = answer->next;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    while (temp1){
        Node* ans = new Node(0);
        ans->data = temp1->data + carry;
        carry = 0;
        if (ans->data > 9){
            carry = ans->data / 10;
            ans->data = ans->data % 10;
        }
        answer->next = ans;
        answer = ans;
        temp1 = temp1->next;
    }

    while (temp2){
        Node* ans = new Node(0);
        ans->data = temp2->data + carry;
        carry = 0;
        if (ans->data > 9){
            carry = ans->data / 10;
            ans->data = ans->data % 10;
        }
        answer->next = ans;
        answer = ans;
        temp2 = temp2->next;
    }

    if (carry){
        Node* ans = new Node(0);
        ans->data = carry;
        answer->next = ans;
    }

    return ReverseLL(result->next);
}

int main(){
	int n, m;
	cin >> n >> m;
	vector<int> arr1(n,0);
	vector<int> arr2(m,0);
	for (int i = 0; i < n; i++){
		cin >> arr1[i];
	}
	for (int i = 0; i < m; i++){
		cin >> arr2[i];
	}

	Node* head1 = ConvertArr2LL(arr1, n);
	Node* head2 = ConvertArr2LL(arr2, m);

	Node* ans = SumofLL(head1, head2);

	Node* temp = ans;
	while (temp){
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}