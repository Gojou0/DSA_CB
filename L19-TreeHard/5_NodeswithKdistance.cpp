#include <iostream>
#include <vector>
#include<queue>
#include<map>
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

Node* find(Node* root, int tar){
    if (!root || root->data == tar) return root;

    Node* found;
    found = find(root->left, tar);
    if (!found){
        found = find(root->right, tar);
    }

    return found;
}

void mapParents(Node* root, map<Node*, Node*> &parents){
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()){
        Node* curr = q.front();
        q.pop();

        if (curr->left){
            parents[curr->left] = curr;
            q.push(curr->left);
        }
        if (curr->right){
            parents[curr->right] = curr;
            q.push(curr->right);
        }
    }
}

vector<int> distanceK(Node* root, Node* target, int k){
    vector<int> ans;
    map<Node*, Node*> parents;
    mapParents(root, parents);          // map parents to access parents of nodes 

    queue<Node*> q;
    map<Node*, bool> vis;
    q.push(target);
    vis[target] = true;
    int dis = 0;

    while (!q.empty()){
        int n = q.size();
        if (dis == k) break;            // push until distance is equals to k

        for (int i = 0; i < n; i++){
            Node* curr = q.front();
            q.pop();

            if (curr->left && !vis[curr->left]){            // check in left (downwards)
                q.push(curr->left);
                vis[curr->left] = true;
            }
            if (curr->right && !vis[curr->right]){              // check in right (downwards)
                q.push(curr->right);
                vis[curr->right] = true;
            }
            if (parents[curr] && !vis[parents[curr]]){              // check upward (parents)
                q.push(parents[curr]);
                vis[parents[curr]] = true;
            }
        }
        dis++;
    }

    while (!q.empty()){
        Node* node = q.front();
        q.pop();
        ans.push_back(node->data);
    }

    return ans;
}

int main(){
    Node* root = Build();

    int tar, k;
    cin >> tar >> k;

    Node* target = find(root, tar);

    vector<int> ans = distanceK(root, target, k);

    for (auto i : ans){
        cout << i << " ";
    }
    cout << endl;
}