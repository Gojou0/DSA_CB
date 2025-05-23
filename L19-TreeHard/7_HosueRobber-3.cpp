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

pair<int, int> Solve(Node* root){
    if (!root) return {0, 0};

    pair<int, int> left = Solve(root->left);
    pair<int, int> right = Solve(root->right);

    int p1 = root->data + left.second + right.second;   // leftsub ka root nhi liya kyuki curr le rkha h
    int p2 = max(left.first, left.second) + max(right.second, right.first);         // curr nhi liya...to dono sub k max lelo

    // p1 -> root ko luta
    // p2 -> root ko nhi luta
    return {p1,p2};
}

int rob(Node* root){
    pair<int, int> ans = Solve(root);
    return max(ans.first, ans.second);
}

int main(){
    Node* root = Build();
    int ans = rob(root);
    cout << ans << endl;
}