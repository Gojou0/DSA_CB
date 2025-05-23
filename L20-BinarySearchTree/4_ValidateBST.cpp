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

Node* insertBST(Node* root, int data){
    if (!root){
        root = new Node(data);
        return root;
    }

    if (data < root->data){
        root->left = insertBST(root->left, data);
    }else{
        root->right = insertBST(root->right, data);
    }

    return root;
}

Node* BuildBST(){
    Node* root = NULL;
    int data;
    cin >> data;
    while (data != -1){
        root = insertBST(root, data);
        cin >> data;
    }

    return root;
}

// Brute Force

// class Solution {
//     public:
//         long leftval(TreeNode* root){
//             if (!root) return -1e14;
    
//             int maxiL = leftval(root->left);
//             int maxiR = leftval(root->right);
    
//             return max(root->val, max(maxiL, maxiR));
//         }
//         long rightval(TreeNode* root){
//             if (!root) return 1e14;
    
//             int miniL = rightval(root->left);
//             int miniR = rightval(root->right);
     
//             return min(root->val, min(miniL, miniR));
//         }
//         bool isValidBST(TreeNode* root) {
//             if (!root || (!root->left && !root->right)) return true;
            
//             long leftmaxi = leftval(root->left);
//             long rigthmini = rightval(root->right);
    
//             bool val = root->val < rigthmini && root->val > leftmaxi;
    
//             if (val && isValidBST(root->left) && isValidBST(root->right)) return true;
    
//             return false;
//         }
// };

bool isValidate(Node* root, int mi = INT_MIN, int mx = INT_MAX){
    if (!root) return true;

    bool val = root->data > mi && root->data < mx;
    // In left sub ...change max to root value
    // In right sub ... change min to root val
    if (val && isValidate(root->left, mi, root->data) && isValidate(root->right, root->data, mx)) return true;

    return false;
}

int main(){
    Node* root = BuildBST();
    cout << isValidate(root);
    return 0;
}