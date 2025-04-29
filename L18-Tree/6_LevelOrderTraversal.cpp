#include <iostream>
#include <vector>
#include<queue>
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

void BFS(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()){
        Node* f = q.front();
        q.pop();
        if (f){
            cout << f->data << " "; 
            // push the child elements
            if (f->left) q.push(f->left);         
            if (f->right) q.push(f->right);
        }else{                          // agr null h to next line me jao...means change the level
            cout << endl;
            if (!q.empty()) q.push(NULL);           // agr empty abhi bhi nhi hui to null daldo level pura hone k liye
        }
    }
}

int main(){
    Node* root = Build();
    BFS(root);
}