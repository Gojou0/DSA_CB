#include<iostream>
#include<unordered_map>
using namespace std;

class LFUCache {
    public:
        class Node {
        public:
            int key;
            int data;
            int counter;
            Node* next;
            Node* back;
    
            Node(int key1, int data1, int counter1 = 1) {
                key = key1;
                data = data1;
                counter = counter1;
                next = nullptr;
                back = nullptr;
            }
        };
    
        void deletenode(Node* n) {
            Node* prev = n->back;
            Node* front = n->next;
            prev->next = front;
            front->back = prev;
        }
    
        void insertnode(Node* n) {
            Node* currheadnext = head->next;
            head->next = n;
            n->back = head;
            n->next = currheadnext;
            currheadnext->back = n;
        }
    
        int capa;
        Node* head;
        Node* tail;
        unordered_map<int, Node*> mp;
    
        LFUCache(int capacity) {
            capa = capacity;
            mp.clear();
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head->next = tail;
            tail->back = head;
        }
    
        int get(int key) {
            if (mp.find(key) != mp.end()) {
                Node* n = mp[key];
                n->counter = n->counter + 1;
                deletenode(n);
                insertnode(n); // insert after head ...to get LRU order correctly
                return n->data;
            } else {
                return -1;
            }
        }
    
        void put(int key, int value) {
            if (mp.find(key) != mp.end()) {
                Node* n = mp[key];
                n->counter = n->counter+1;
                n->data = value; // if present ....only change the value
                deletenode(n);
                insertnode(n);
            } else {
                if (mp.size() == capa) {
                    int mini = INT_MAX;
                    Node* temp = head->next;
                    Node* n = nullptr;
                    while (temp != tail){
                        if (mini >= temp->counter){
                            n = temp;
                            mini = temp->counter;
                        }
                        temp = temp->next;
                    }
                    mp.erase(n->key);
                    deletenode(n);
                }
                Node* newnode = new Node(key, value); // and insert after head
                mp[key] = newnode;
                insertnode(newnode);
            }
        }
};

int main(){
    int capacity = 2;
    LFUCache* obj = new LFUCache(capacity);
    obj->put(2,-5);
    int key = 2;
    int param_1 = obj->get(key);
    cout << param_1 << endl;
}