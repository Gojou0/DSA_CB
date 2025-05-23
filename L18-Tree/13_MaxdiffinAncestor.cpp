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

int Maxdiff(Node* root, int maxval, int minval){
    if (!root) return maxval - minval;

    maxval = max(maxval, root->data);
    minval = min(minval, root->data);

    int left = Maxdiff(root->left, maxval, minval);
    int right = Maxdiff(root->right, maxval, minval);

    return max(left, right);
}

int main(){
    Node* root = Build();
    cout << Maxdiff(root, root->data, root->data) << endl;
}