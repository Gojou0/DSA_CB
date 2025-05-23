#include<iostream>
#include<vector>
#include<map>
using namespace std;

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

Node* BuildTree(vector<int> &preorder, int pre_st, int pre_end, vector<int> &inorder, int in_st, int in_end, map<int, int> &inmp){
    if (pre_st > pre_end || in_st > in_end) return NULL;

    Node* root = new Node(preorder[pre_st]);

    int in_root_idx = inmp[root->data];             // find index of root ele in inorder vector
    int left_ele = in_root_idx - in_st;         // left to that index will act as inorder for left sub tree and vice versa

    root->left = BuildTree(preorder, pre_st+1, pre_st + left_ele, inorder, in_st, in_root_idx - 1, inmp);
    root->right = BuildTree(preorder, pre_st + left_ele + 1, pre_end, inorder, in_root_idx + 1, in_end, inmp);

    return root;
}


int main(){
    vector<int> preorder;
    vector<int> inorder;
    preorder.push_back(3);
    preorder.push_back(9);
    preorder.push_back(20);
    preorder.push_back(15);
    preorder.push_back(7);

    inorder.push_back(9);
    inorder.push_back(3);
    inorder.push_back(15);
    inorder.push_back(20);
    inorder.push_back(7);

    map<int, int> inmp;
    for (int i = 0; i < inorder.size(); i++){
        inmp[inorder[i]] = i;
    }

    Node* root = BuildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inmp);
    cout << root->data << endl;
}