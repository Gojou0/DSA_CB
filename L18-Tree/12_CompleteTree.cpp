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

bool isComplete(Node* root){
    queue<Node*> q;
    q.push(root);
    bool seennull = false;
    while (!q.empty()){
        Node* curr = q.front();
        q.pop();
        if (!curr) seennull = true;
        else{
            if (seennull) return false;
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    return true;
}

int main(){
    Node* root = Build();
    cout << isComplete(root) << endl;
}