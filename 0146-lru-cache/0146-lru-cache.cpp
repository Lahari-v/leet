class Node {
    public:
        int key;
        int value;
        Node* next;
        Node* prev;

        Node(int key, int value) {
            this->key = key;
            this->value = value;
            prev = nullptr;
            next = nullptr;
        }
};
class LRUCache {
public:
    int capacity;
    unordered_map<int, Node*> map;
    Node* head;
    Node* tail;
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(map.find(key) != map.end()) {
            Node* node = map[key];
            remove(node);
            insertAtHead(node);
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(map.find(key) != map.end()) {
            Node* node = map[key]; 
            remove(node); 
        }
        Node* node = new Node(key, value);
        map[key] = node;
        insertAtHead(node);

        if(map.size() > capacity) { 
            Node* node = tail->prev;
            remove(node);
            map.erase(node->key);
            delete node;
        }
    }

    void insertAtHead(Node* node) { 
        Node* temp = head->next;
        head->next = node;
        node->prev = head;
        node->next = temp;

        if(temp != nullptr)
            temp->prev = node;
    }

    void remove(Node* node) {
        Node* prevv = node->prev;
        Node* nextt = node->next;
        prevv->next = nextt;
        nextt->prev = prevv;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
