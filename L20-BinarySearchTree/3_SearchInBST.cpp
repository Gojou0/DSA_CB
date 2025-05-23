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

Node* Search(Node* root, int val){
    if (!root) return NULL;

    if (val == root->data) return root;

    Node* node;
    if (val < root->data){
        node = Search(root->left, val);
    }else{
        node = Search(root->right, val);
    }

    return node;
}

int main(){
    Node* root = BuildBST();
    int val;
    cin >> val;
    Node* node = Search(root, val);
    cout << node->data << endl;
    return 0;
}