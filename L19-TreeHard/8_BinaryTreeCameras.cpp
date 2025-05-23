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
// Never place camera on leaf nodes until it is the main root of tree

// CASE 1 : Camera laga hai left ya right k root me .... camera not needed ...return statement -> UNDER VIGILANCE (UV)
// CASE 2 : Na bacho pr camera hai or na hi wo vigilance me h ....so camera needed... return statement -> CAMERA LAGA DIA (CLD)
// CASE 3 : bacho pr camera nhi h ...but wo vigilance me h.....so rertun root is not in vigilance...so uper ka tree use dekh ske...
//          Now this node will act as leaf node only.....return statement -> CAMERA CHAHIYE (CC) or CAMERANHILAGA (CNL)

#define CAMERACHAHIYE 0
#define CAMERALAGADIA 1
#define UNDERVIGILANCE 2

int minCam(Node* root, int &ans){
    if (!root) return UNDERVIGILANCE;

    int left = minCam(root->left, ans);
    int right = minCam(root->right, ans);

    if (left == CAMERACHAHIYE || right == CAMERACHAHIYE){
        ans++;
        return CAMERALAGADIA;
    }else if (left == CAMERALAGADIA || right == CAMERALAGADIA){
        return UNDERVIGILANCE;
    }else{
        // Both the children are undervigilance ... act as leaf node
        return CAMERACHAHIYE;
    }

}

int main(){
    Node* root = Build();

    int ans = 0;
    int YO = minCam(root, ans);
    cout << ans << endl;
}