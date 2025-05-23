// #include <iostream>
// #include<vector>
// #include<string>
// #include<unordered_map> 
// using namespace std; 
// class Node{ 
//     public: 
//     string x;
//     Node* parent; 
//     vector<Node*> des;
//     int lockby; 

//     Node (string data){ 
//         x = data; 
//         parent = nullptr; 
//         lockby = -1; 
//     }  
// };

// unordered_map<string, Node*> mp;            // store address of each node via their names

// void Build(vector<string> nodes, int m){ 
//     for (auto i : nodes){
//         mp[i] = new Node(i);
//     }

//     for (int i = 1; i < nodes.size(); i++){
//         Node* parent = mp[nodes[(i-1) / m]];            // mapping of level order traversal with array indexes
//         Node* child = mp[nodes[i]];
//         child->parent = parent;
//         parent->des.push_back(child);
//     }
// }

// bool islockancestor(Node* name) { 
//     Node* temp = name; 
//     while (temp){ 
//         if (temp->lockby != -1) return true; 
//         temp = temp->parent; 
//     }
//     return false; 
// }

// bool islockdes(Node* name){
//     // Base case:
//     if (name->lockby != -1) return true;

//     // Recursive case:
//     for (auto i : name->des){
//         if (islockdes(i)) return true;
//     }
//     return false;
// }

// bool Lock(string node, int uid){ 
//     Node* name = mp [node]; 
//     if (name->lockby != -1 || islockancestor(name) || islockdes(name)){ 
//         return false;
//     }

//     name->lockby = uid;
//     return true;
// }

// bool Unlock(string node, int uid){
//     Node* name = mp[node];
//     if (name->lockby == uid){
//         name->lockby = -1;
//         return true;
//     }
//     return false;
// }

// bool getlockdes(Node* name, int uid, vector<Node*> &lockeddes){
//     for (auto i : name->des){
//         if (i->lockby != -1){
//             if (i->lockby != uid){
//                 return true;            // there is a locked des but with other uid ....final answer should be false
//             }
//             lockeddes.push_back(i);
//         }
//         if (getlockdes(i, uid, lockeddes)) return true;       
//     }
//     return false;
// }

// bool Upgrade(string node, int uid){
//     Node* name = mp[node];
//     if (name->lockby != -1 || islockancestor(name)) return false;       // first check if it is locked or have any ancestor locked

//     vector<Node*> lockeddes;            // now find all locked des of it with this uid in this vector
//     bool lockbyotheruser = getlockdes(name, uid, lockeddes);
//     if (lockbyotheruser || lockeddes.empty()) return false;

//     name->lockby = uid;         // lock it by this uid
//     for (auto i : lockeddes){       // unlock all its locked des with that same uid
//         i->lockby = -1;
//     }
//     return true;
// }

// int main(){
//     int n, m;
//     cin >> n >> m;
//     vector<string> nodes;
//     for (int i = 0; i < n; i++){
//         string str;
//         cin >> str;
//         nodes.push_back(str);
//     }
//     Build(nodes, m);

//     int op, uid;
//     string node;
//     while (cin >> op >> node >> uid) {
//         if (op == 1) {
//             cout << (Lock(node, uid) ? "true " : "false ");
//         } else if (op == 2) {
//             cout << (Unlock(node, uid) ? "true " : "false ");
//         } else if (op == 3) {
//             cout << (Upgrade(node, uid) ? "true " : "false ");
//         }  
//     }
//     return 0;
// }

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Node {
public:
    string x;
    Node* parent;
    vector<Node*> des;
    int lockby;
    int lockedDescendants; // Optimization

    Node(string data) {
        x = data;
        parent = nullptr;
        lockby = 0;
        lockedDescendants = 0;
    }
};

unordered_map<string, Node*> mp;

void Build(vector<string> nodes, int m) {
    for (auto i : nodes) {
        mp[i] = new Node(i);
    }

    for (int i = 1; i < nodes.size(); i++) {
        Node* parent = mp[nodes[(i - 1) / m]];
        Node* child = mp[nodes[i]];
        child->parent = parent;
        parent->des.push_back(child);
    }
}

void updateAncestors(Node* node, int delta) {
    while (node) {
        node->lockedDescendants += delta;
        node = node->parent;
    }
}

bool islockancestor(Node* name) {
    Node* temp = name->parent;
    while (temp) {
        if (temp->lockby != 0) return true;
        temp = temp->parent;
    }
    return false;
}

bool islockdes(Node* name) {
    return name->lockedDescendants > 0;
}

bool Lock(string node, int uid) {
    Node* name = mp[node];
    if (name->lockby != 0 || islockancestor(name) || islockdes(name)) {
        return false;
    }
    name->lockby = uid;
    updateAncestors(name->parent, 1);
    return true;
}

bool Unlock(string node, int uid) {
    Node* name = mp[node];
    if (name->lockby == uid) {
        name->lockby = 0;
        updateAncestors(name->parent, -1);
        return true;
    }
    return false;
}

void getlockdes(Node* name, int uid, vector<Node*>& lockeddes, bool& hasOtherUserLock) {
    for (auto i : name->des) {
        if (i->lockby != 0) {
            if (i->lockby != uid) hasOtherUserLock = true;
            else lockeddes.push_back(i);
        }
        if (i->lockedDescendants > 0){
            getlockdes(i, uid, lockeddes, hasOtherUserLock);
        }
    }
}

bool Upgrade(string node, int uid) {
    Node* name = mp[node];
    if (name->lockby != 0 || islockancestor(name) || name->lockedDescendants == 0) return false;

    vector<Node*> lockeddes;
    bool hasOtherUserLock = false;
    getlockdes(name, uid, lockeddes, hasOtherUserLock);

    if (hasOtherUserLock || lockeddes.empty()) return false;

    for (auto i : lockeddes) {
        i->lockby = 0;
        updateAncestors(i->parent, -1);
    }

    name->lockby = uid;
    updateAncestors(name->parent, 1);
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> nodes(n);
    for (int i = 0; i < n; i++) {
        cin >> nodes[i];
    }
    Build(nodes, m);

    int op, uid;
    string node;
    while (cin >> op >> node >> uid) {
        if (op == 1) {
            cout << (Lock(node, uid) ? "true " : "false ");
        } else if (op == 2) {
            cout << (Unlock(node, uid) ? "true " : "false ");
        } else if (op == 3) {
            cout << (Upgrade(node, uid) ? "true " : "false ");
        }
    }
    return 0;
}
