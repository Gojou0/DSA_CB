#include <iostream>
#include <vector>
#include<queue>
#include<map>
#include<set>
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

vector<vector<int> > VOT(Node* root){
    map<int, map<int, multiset<int> > > nodes;
    // first int -> verticals ke liye (x axis)
    // second int -> levels ke liye (y axis)
    // multiset -> multiple node values at same coordinates ke liye
    queue<pair<Node*, pair<int, int> > > q;
    q.push({root, {0, 0}});

    while (!q.empty()){
        pair<Node*, pair<int, int> > curr = q.front();
        q.pop();

        Node* node = curr.first;
        int x = curr.second.first; 
        int y = curr.second.second;

        nodes[x][y].insert(node->data);             // multiset me values insert krdo

        if (node->left){
            q.push({node->left, {x-1, y+1}});           // left side me vertical(x-axis) kam hoga
        }
        if (node->right){
            q.push({node->right, {x+1, y+1}});          // right side me verticsls badega
        }  
    }

    vector<vector<int> > ans;
    for (auto a : nodes){
        vector<int> col;
        for (auto b : a.second){
            col.insert(col.end(), b.second.begin(), b.second.end());
        }
        ans.push_back(col);
    }

    return ans;
}

int main(){
    Node* root = Build();

    vector<vector<int> > ans = VOT(root);

    for (auto i : ans){
        for (auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
}