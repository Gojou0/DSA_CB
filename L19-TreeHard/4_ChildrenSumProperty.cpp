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

void ChildSum(Node* root){
    if (!root) return;

    int sum = 0;
    if (root->left){
        sum += root->left->data;
    }
    if (root->right){
        sum += root->right->data;
    }

    if (sum >= root->data) root->data = sum;        // agr sum bada h ...to root me badi value krdo
    else{                                                   // agr sum chota h to ...children me root ki value daldo
        if (root->left){
            root->left->data = root->data;
        }
        if (root->right){
            root->right->data = root->data;
        }
    }

    ChildSum(root->left);
    ChildSum(root->right);

    int sum_backtrack = 0;
    if (root->left) sum_backtrack += root->left->data;
    if (root->right) sum_backtrack += root->right->data;

    if (root->left || root->right) root->data = sum_backtrack;              // leaf nodes k alawa sum ki values root me dalte jao
}

int main(){
    Node* root = Build();

    ChildSum(root);

    cout << root->data << endl;
}