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

int dfs(Node* root, int target, long long currsum, unordered_map<long long, int> prefixsum){
    if (!root) return 0;

    currsum += root->data * 1LL;
    int count = prefixsum[currsum - target];
    
    prefixsum[currsum]++;
    count += dfs(root->left, target, currsum, prefixsum);
    count += dfs(root->right, target, currsum, prefixsum);
    prefixsum[currsum]--;

    return count;
}

int main(){
    Node* root = Build();

    int target;
    cin >> target;
    unordered_map<long long, int> prefixsum;
    prefixsum[0] = 1;
    cout << dfs(root, target, 0, prefixsum) << endl;
}