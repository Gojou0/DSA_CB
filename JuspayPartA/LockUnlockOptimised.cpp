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
    int lockedDescendants;

    Node(string data) {
        x = data;
        parent = nullptr;
        lockby = -1;
        lockedDescendants = 0;
    }
};

unordered_map<string, Node*> mp;

void Build(const vector<string>& nodes, int m) {
    int n = nodes.size();
    for (const auto& name : nodes) {
        mp[name] = new Node(name);
    }
    for (int i = 0; i < n; i++) {
        Node* curr = mp[nodes[i]];
        int firstChildIndex = m * i + 1;
        for (int j = 0; j < m; j++) {
            int childIndex = firstChildIndex + j;
            if (childIndex >= n) break;  // careful bounds check
            Node* child = mp[nodes[childIndex]];
            child->parent = curr;
            curr->des.push_back(child);
        }
    }
}

void updateAncestors(Node* node, int delta) {
    while (node) {
        node->lockedDescendants += delta;
        node = node->parent;
    }
}

bool hasLockedAncestor(Node* node) {
    Node* temp = node->parent;
    while (temp) {
        if (temp->lockby != -1) return true;
        temp = temp->parent;
    }
    return false;
}

bool Lock(string node, int uid) {
    Node* n = mp[node];
    if (n->lockby != -1 || hasLockedAncestor(n) || n->lockedDescendants > 0) {
        return false;
    }
    n->lockby = uid;
    updateAncestors(n->parent, 1);
    return true;
}

bool Unlock(string node, int uid) {
    Node* n = mp[node];
    if (n->lockby == uid) {
        n->lockby = -1;
        updateAncestors(n->parent, -1);
        return true;
    }
    return false;
}

void getLockedDescendants(Node* node, vector<Node*>& lockedNodes) {
    for (auto child : node->des) {
        if (child->lockby != -1) {
            lockedNodes.push_back(child);
        }
        if (child->lockedDescendants > 0) {
            getLockedDescendants(child, lockedNodes);
        }
    }
}

bool Upgrade(string node, int uid) {
    Node* n = mp[node];
    if (n->lockby != -1 || hasLockedAncestor(n) || n->lockedDescendants == 0) {
        return false;
    }
    vector<Node*> lockedNodes;
    getLockedDescendants(n, lockedNodes);

    // Check if all locked descendants belong to the same user
    for (auto lockedNode : lockedNodes) {
        if (lockedNode->lockby != uid) {
            return false;
        }
    }
    // Unlock all locked descendants
    for (auto lockedNode : lockedNodes) {
        lockedNode->lockby = -1;
        updateAncestors(lockedNode->parent, -1);
    }
    // Lock the current node
    n->lockby = uid;
    updateAncestors(n->parent, 1);
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
        bool res = false;
        if (op == 1) {
            res = Lock(node, uid);
        } else if (op == 2) {
            res = Unlock(node, uid);
        } else if (op == 3) {
            res = Upgrade(node, uid);
        }
        cout << (res ? "true " : "false ");
    }
    return 0;
}
