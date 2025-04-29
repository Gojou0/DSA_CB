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

Node* LCA(Node* root, int p, int q){
    // Base case
    if (!root || p == root->data || q == root->data){               // agr node match ho jaye to wahi return krdo
        return root;
    }
    Node* left = LCA(root->left, p, q);         //left me dhundo
    Node* right = LCA(root->right, p, q);           // right me dhundo

    // Results
    if (!left){         // agr left null ho to right return krdo and vice versa
        return right;
    }else if (!right){
        return left;
    }else{                  // agr dono null nhi h mtlb ancestor mil gya
        return root;
    }
}

int main(){
    Node* root = Build();

    int p, q;
    cin >> p >> q;

    Node* ans = LCA(root, p, q);
    cout << ans->data << endl;
}