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

void Leftview(Node* root, int l, int &maxl){
    if (!root) return;

    if (l > maxl){
        cout << root->data << " ";
        maxl = l;
    }

    Leftview(root->left, l+1, maxl);
    Leftview(root->right, l+1, maxl);
}

void Rightview(Node* root, int l, int &maxl){
    if (!root) return;

    if (l > maxl){
        cout << root->data << " ";
        maxl = l;
    }

    Rightview(root->right, l+1, maxl);
    Rightview(root->left, l+1, maxl);
}

int main(){
    Node* root = Build();
    int maxl = -1;
    Leftview(root, 0, maxl);
    maxl = -1;
    cout << endl;
    Rightview(root, 0, maxl);
}