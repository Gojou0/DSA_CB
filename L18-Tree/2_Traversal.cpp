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

void Preorder(Node* root){
    if (!root) return;

    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}

void Inorder(Node* root){
    if (!root) return;

    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

void Postorder(Node* root){
    if (!root) return;

    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}

int main(){
    Node* root = Build();
    Preorder(root);
    cout << endl;
    Inorder(root);
    cout << endl;
    Postorder(root);
    cout << endl;
    return 0;
}