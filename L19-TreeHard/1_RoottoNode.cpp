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

bool getpath(Node* root, vector<int> &arr, int x){
    if (!root) return false;

    arr.push_back(root->data);

    if (root->data == x){
        return true;
    }

    if (getpath(root->left, arr, x) || getpath(root->right, arr, x)) return true;

    arr.pop_back();
    return false;
}

int main(){
    Node* root = Build();
    vector<int> arr;
    int x;
    cin >> x;
    getpath(root, arr, x);

    for (auto i : arr){
        cout << i << " ";
    }
    cout << endl;
}
