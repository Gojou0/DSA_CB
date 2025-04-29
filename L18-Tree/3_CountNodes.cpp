#include <iostream>
#include <vector>
#include <utility>
using namespace std;

// Self Defining Datatype for node (Self referential)
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

int CountNodes(Node* root){
    if (!root) return 0;

    return 1 + CountNodes(root->left) + CountNodes(root->right);
}

int Height(Node* root){                 // O(n)
    if (!root) return 0;

    int lh = Height(root->left);
    int rh = Height(root->right);

    return 1 + max(lh, rh);
}

int Diameter(Node* root){                   // O(n^2) due to caling of height fn at each node
    if (!root) return 0;      // leaf node pr diameter 0 hi hoga

    int rd = Height(root->left) + Height(root->right);  // option 1 -> root ko inlcude krke 

    int dl = Diameter(root->left);          // option 2 -> leftsubtree me diameter dhund lo
    int dr = Diameter(root->right);         // option 3 -> rightsubtree me diameter dhund lo

    return max(rd, max(dl, dr));    // maximum of all three option is answer
}

// Diameter in O(n)
pair<int, int> OptiDiameter(Node* root){                   // O(n^2)
    if (!root) return {0,0};

    pair<int, int> pair1 = OptiDiameter(root->left);            // take pair in which firts -> height and second -> diameter
    pair<int, int> pair2 = OptiDiameter(root->right);

    // Options for diamter
    int rootd = pair1.first + pair2.first;     
    int leftd = pair1.second;
    int rightd = pair2.second;

    return {1 + max(pair1.first, pair2.first), max(rootd, max(leftd, rightd))};
}

int main(){
    Node* root = Build();
    cout << CountNodes(root) << endl;
    cout << Height(root) << endl;
    cout << Diameter(root) << endl;
    cout << OptiDiameter(root).first << endl;
    cout << OptiDiameter(root).second << endl;
}