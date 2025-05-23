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

vector<int> MorrisIn(Node* root){
    vector<int> inorder;
    Node* temp = root;
    while (temp){
        if (!temp->left){
            inorder.push_back(temp->data);
            temp = temp->right;
        }else{
            Node* prev = temp->left;
            while (prev->right && prev->right != temp){
                prev = prev->right;
            }
            if (!prev->right){                  // create thread and move to left
                prev->right = temp;
                temp = temp->left;
            }else{                              // remove thread ...means visited and move to right
                prev->right = NULL;
                inorder.push_back(temp->data);          // add root while removing....coz its inorder
                temp = temp->right;
            }
        }
    }
    return inorder;
}

int main(){
    Node* root = Build();
    vector<int> inorder = MorrisIn(root);
    for (auto i : inorder){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}