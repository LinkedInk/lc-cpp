#include "pasta\headers.cpp"

struct Node {
    int val;
    int key;
    Node* prev;
    Node* next;
};

class LRUCache {
public:
    Node* tail;
    Node* head;
    unordered_map<int, Node*> map;
    int size;
    int maxSize;
    LRUCache(int capacity) {
        map.reserve(capacity);
        size = 0;
        maxSize = capacity;
        Node* dummy = new Node();
        dummy->next = nullptr;
        tail = dummy;
        head = dummy;
    }
    
    int get(int key) {
        if (map.count(key)) {
            moveNodeToFront(map.at(key));
            return map.at(key)->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (map.count(key)) { // update flow
            map.at(key)->val = value;
            Node* toBeMoved = map.at(key);
            moveNodeToFront(toBeMoved);
        } else {
            // new node flow
            if (size == maxSize) { // delete op
                deleteNode();
            }
            
            Node* NN = new Node();
            NN->val = value;
            NN->key = key;
            NN->prev = head;
            head->next = NN;
            head = NN;
            size++;
            
            map.emplace(key, NN);
        }
        printFromLast();
    }
    void deleteNode() {
        Node* TBR = tail->next;
        map.erase(TBR->key);
        if (head == TBR) {
            head = TBR->prev;
            head->next = nullptr;
        } else {
            TBR->prev->next = TBR->next;
            TBR->next->prev = TBR->prev;
        }
        delete TBR;
    }
    void moveNodeToFront(Node* toBeMoved) {
        if (head != toBeMoved) {
            toBeMoved->prev->next = toBeMoved->next;
            toBeMoved->next->prev = toBeMoved->prev;
            head->next = toBeMoved;
            toBeMoved->prev = head;
            head = toBeMoved;
        }
    }
    void printFromLast() {
        Node* curr = tail;
        while (curr->next != nullptr) {
            cout << curr->next->val << endl;
            curr = curr->next;
        }
    }
};