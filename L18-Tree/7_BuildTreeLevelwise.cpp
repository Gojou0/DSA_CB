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

Node* BuildLevelwise(){
    cout << "Enter Root Data : ";
    int data;
    cin >> data;
    queue<Node*> q;
    if (data == -1) return NULL;

    Node* root = new Node(data);
    q.push(root);

    while (!q.empty()){
        Node* front = q.front();
        q.pop();
        cout << "Enter Children of " << front->data << ": ";
        int l, r;
        cin >> l >> r;
        if (l != -1){
            front->left = new Node(l);
            q.push(front->left);
        }
        if (r != -1){
            front->right = new Node(r);
            q.push(front->right);
        }
    }
    return root;
}

int main(){
    Node* root = BuildLevelwise();
}