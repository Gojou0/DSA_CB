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

Node* insertBST(Node* root, int data){
    if (!root){
        root = new Node(data);
        return root;
    }

    if (data < root->data){
        root->left = insertBST(root->left, data);
    }else{
        root->right = insertBST(root->right, data);
    }

    return root;
}

Node* BuildBST(){
    Node* root = NULL;
    int data;
    cin >> data;
    while (data != -1){
        root = insertBST(root, data);
        cin >> data;
    }

    return root;
}

void Print(Node* root, int k1, int k2){
    if (!root) return;

    if (root->data > k1 && root->data < k2){
        Print(root->left, k1, k2);
        cout << root->data << " ";
        Print(root->right, k1, k2);
    }else if (root->data > k2){
        Print(root->left, k1, k2);
    }else{
        Print(root->right, k1, k2);
    }
}

int main(){
    Node* root = BuildBST();
    int k1, k2;
    cin >> k1 >> k2;
    Print(root, k1, k2);
    return 0;
}