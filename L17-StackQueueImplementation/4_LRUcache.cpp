#include<iostream>
#include<unordered_map>
using namespace std;

class LRUCache {
    public:
        class Node {
        public:
            int key;
            int data;
            Node* next;
            Node* back;
    
            Node(int key1, int data1) {
                key = key1;
                data = data1;
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
    
        int n;
        Node* head;
        Node* tail;
        unordered_map<int, Node*> mp;
    
        LRUCache(int capacity) {
            n = capacity;
            mp.clear();
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head->next = tail;
            tail->back = head;
        }
    
        int get(int key) {
            if (mp.find(key) != mp.end()) {
                Node* n = mp[key];
                deletenode(n);
                insertnode(n);              // insert after head ...to get LRU order correctly
                return n->data;
            } else {
                return -1;
            }
        }
    
        void put(int key, int value) {
            if (mp.find(key) != mp.end()) {
                Node* n = mp[key];              
                n->data = value;            // if present ....only change the value
                deletenode(n);
                insertnode(n);
            } else {
                if (mp.size() == n) {
                    Node* n = tail->back;           // if size exceeded delete from last(LRU order)
                    mp.erase(n->key);
                    deletenode(n);
                }
                Node* n = new Node(key, value);    // and insert after head
                mp[key] = n;
                insertnode(n);
            }
        }
};

int main(){
    int capacity = 2;
    LRUCache* obj = new LRUCache(capacity);
    obj->put(2,-5);
    int key = 2;
    int param_1 = obj->get(key);
    cout << param_1 << endl;
}