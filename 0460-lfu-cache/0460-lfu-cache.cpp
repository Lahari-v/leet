#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int key, value, cnt;
    Node* prev;
    Node* next;

    Node(int _key, int _value) {
        key = _key;
        value = _value;
        cnt = 1; // Initialize frequency to 1
        prev = nullptr;
        next = nullptr;
    }
};

class List {
public:
    int size;
    Node* head;
    Node* tail;

    List() {
        head = new Node(0, 0); // Dummy head
        tail = new Node(0, 0); // Dummy tail
        head->next = tail;
        tail->prev = head;
        size = 0; // Initially, the list is empty
    }

    void addFront(Node* node) {
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++;
    }

    void removeNode(Node* delNode) {
        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
        size--;
    }
};

class LFUCache {
private:
    map<int, Node*> keynode;          // Map key to Node
    map<int, List*> freqlistmap;      // Map frequency to List of nodes
    int maxsizecache;                 // Maximum capacity of the cache
    int minfreq;                      // Minimum frequency of nodes in the cache
    int currsize;                     // Current size of the cache

    void updateFreqListMap(Node* node) {
        // Remove node from its current frequency list
        keynode.erase(node->key);
        freqlistmap[node->cnt]->removeNode(node);

        // Update minimum frequency if necessary
        if (node->cnt == minfreq && freqlistmap[node->cnt]->size == 0) {
            minfreq++;
        }

        // Add node to the next higher frequency list
        List* nextHigherFreqList = new List();
        if (freqlistmap.find(node->cnt + 1) != freqlistmap.end()) {
            nextHigherFreqList = freqlistmap[node->cnt + 1];
        }
        node->cnt++; // Increment frequency
        nextHigherFreqList->addFront(node);
        freqlistmap[node->cnt] = nextHigherFreqList;
        keynode[node->key] = node;
    }

public:
    LFUCache(int capacity) {
        maxsizecache = capacity;
        minfreq = 0;
        currsize = 0;
    }

    int get(int key) {
        if (keynode.find(key) != keynode.end()) {
            Node* node = keynode[key];
            int val = node->value;
            updateFreqListMap(node);
            return val;
        }
        return -1; // Key not found
    }

    void put(int key, int value) {
        if (maxsizecache == 0) {
            return; // Cache has no capacity
        }

        if (keynode.find(key) != keynode.end()) {
            // Update the value of the existing node
            Node* node = keynode[key];
            node->value = value;
            updateFreqListMap(node);
        } else {
            // Check if the cache is full
            if (currsize == maxsizecache) {
                // Evict the least frequently used node
                List* list = freqlistmap[minfreq];
                keynode.erase(list->tail->prev->key);
                freqlistmap[minfreq]->removeNode(list->tail->prev);
                currsize--;
            }

            // Add the new node
            currsize++;
            minfreq = 1; // Reset minimum frequency to 1
            List* list = new List();
            if (freqlistmap.find(minfreq) != freqlistmap.end()) {
                list = freqlistmap[minfreq];
            }
            Node* node = new Node(key, value);
            list->addFront(node);
            keynode[key] = node;
            freqlistmap[minfreq] = list;
        }
    }
};
