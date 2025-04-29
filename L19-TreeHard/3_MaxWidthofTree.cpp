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

int MaxWidth(Node* root){
    if (!root) return 0;

    int ans = 0;
    queue<pair<Node*, int> > q;             // to add indexing level wise
    q.push({root, 0});

    while (!q.empty()){
        pair<Node*, int> p = q.front();
        int min_index = p.second;           // store minimum index at each level
        int n = q.size();

        int first, last;            // since, width = (last - first + 1)
        for (int i = 0; i < n; i++){
            int curr_index = q.front().second - min_index;         // sub min_index from each node's index at same level to prevent overflow
            Node* node = q.front().first;
            q.pop();
            if (i == 0) first = curr_index;             
            if (i == n-1) last = curr_index;

            if (node->left){
                q.push({node->left, 2*curr_index + 1});         // provide indexing based on currindex(root's index) 
            }
            if (node->right){
                q.push({node->right, 2*curr_index + 2});
            }
        }
        ans = max(ans, last - first + 1);
    }
    return ans;
}

int main(){
    Node* root = Build();

    cout << MaxWidth(root) << endl;
}