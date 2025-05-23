#include <iostream>
#include <vector>
#include<utility>
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

pair<Node*, Node*> ConvertLL(Node* root){
    if (!root) return {NULL, NULL};

    if (!root->left && !root->right) {
        return {root, root};
    }
    if (!root->left){
        pair<Node*, Node*> pr = ConvertLL(root->right);
        Node* righthead = pr.first;
        Node* righttail = pr.second;
        root->right = righthead;
        return {root, righttail};
    } 
    if (!root->right){
        pair<Node*, Node*> pl = ConvertLL(root->left);
        Node* lefthead = pl.first;
        Node* lefttail = pl.second;
        lefttail->right = root;
        return {lefthead, root};
    }

    pair<Node*, Node*> pl = ConvertLL(root->left);
    Node* lefthead = pl.first;
    Node* lefttail = pl.second;

    pair<Node*, Node*> pr = ConvertLL(root->right);
    Node* righthead = pr.first;
    Node* righttail = pr.second;

    lefttail->right = root;
    root->right = righthead;

    return {lefthead, righttail};
}

int main(){
    Node* root = BuildBST();

    Node* head = ConvertLL(root).first;
    Node* temp = head;
    while (temp){
        cout << temp->data << endl;
        temp = temp->right;
    }
    return 0;
}