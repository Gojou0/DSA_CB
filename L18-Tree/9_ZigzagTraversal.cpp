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

vector<vector<int> > BFS(Node* root){
    vector<vector<int> > result;
    if (!root) return result;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();
        vector<int> level;

        for (int i = 0; i < n; ++i) {
            Node* node = q.front(); q.pop();
            level.push_back(node->data);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        result.push_back(level);
    }

    return result;
}

int main(){
    Node* root = Build();
    vector<vector<int> > ans = BFS(root);

    for (int i = 0; i < ans.size(); i++){
        if (i % 2 == 0){
            for (int j = 0; j < ans[i].size(); j++){
                cout << ans[i][j] << " ";
            }
        }else{
            for (int j = ans[i].size()-1; j >= 0; j--){
                cout << ans[i][j] << " ";
            }
        }
    }
    cout << endl;
}