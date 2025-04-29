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

int maxpath(Node* root, int &maxp){
    if (!root) return 0;

    int leftsum = max(0, maxpath(root->left, maxp));
    int rightsum = max(0, maxpath(root->right, maxp));

    maxp = max(maxp, (root->data + leftsum + rightsum));

    return root->data + max(leftsum, rightsum);
}

int main(){
    Node* root = Build();

    int maxp = INT_MIN;
    int x = maxpath(root, maxp);
    cout << maxp << endl;
}