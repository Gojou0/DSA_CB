#include <iostream>
#include <vector>
using namespace std;

// Self Defining Datatype for node
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    // Calling Constructor
    Node(int data1, Node* left1, Node* right1){
        data = data1;
        left = left1;
        right = right1;
    }

    Node(int data1){
        data = data1;
        left = nullptr;
        right = nullptr;
    }
};

Node* Build(){
    int data;
    cin >> data;
    if (data == -1) return NULL;

    Node* root = new Node(data);
    root->left = Build();
    root->right = Build();
    return root;
}

Node* Find(Node* root, int data1){
    if (!root) return nullptr;

    if (root->data == data1) return root;
    
    Node* add;
    add = Find(root->left, data1);
    if (add == nullptr){
        add = Find(root->right, data1);
    }

    return add;
}

int main(){
    Node* root = Build();
    int data;
    cin >> data;
    Node* address = Find(root, data);
    if (address) cout << "Found" << endl;
    else cout << " Not found" << endl;
}