// class Node {
//     public:
//         int key;
//         int value;
//         Node* next;
//         Node* prev;

//         Node(int key, int value) {
//             this->key = key;
//             this->value = value;
//             prev = nullptr;
//             next = nullptr;
//         }
// };
// class LRUCache {
// public:
//     int capacity;
//     unordered_map<int, Node*> map;
//     Node* head;
//     Node* tail;
//     LRUCache(int capacity) {
//         this->capacity = capacity;
//         head = new Node(-1, -1);
//         tail = new Node(-1, -1);
//         head->next = tail;
//         tail->prev = head;
//     }
    
//     int get(int key) {
//         if(map.find(key) != map.end()) {
//             Node* node = map[key];
//             remove(node);
//             insertAtHead(node);
//             return node->value;
//         }
//         return -1;
//     }
    
//     void put(int key, int value) {
//         if(map.find(key) != map.end()) {
//             Node* node = map[key]; 
//             remove(node); 
//         }
//         Node* node = new Node(key, value);
//         map[key] = node;
//         insertAtHead(node);

//         if(map.size() > capacity) { 
//             Node* node = head->next;
//             remove(node);
//             map.erase(node->key);
//             delete node;
//         }
//     }

//     void insertAtHead(Node* node) { 
//         Node* temp = head->next;
//         head->next = node;
//         node->prev = head;
//         node->next = temp;

//         if(temp != nullptr)
//             temp->prev = node;
//     }

//     void remove(Node* node) {
//         Node* prevv = node->prev;
//         Node* nextt = node->next;
//         prevv->next = nextt;
//         nextt->prev = prevv;
//     }
// };

// /**
//  * Your LRUCache object will be instantiated and called as such:
//  * LRUCache* obj = new LRUCache(capacity);
//  * int param_1 = obj->get(key);
//  * obj->put(key,value);
//  */
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
        head = new Node(-1, -1);  // Dummy head node
        tail = new Node(-1, -1);  // Dummy tail node
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(map.find(key) != map.end()) {
            Node* node = map[key];
            remove(node);            // Remove the node from the list
            insertAtHead(node);      // Insert the node at the head (most recently used)
            return node->value;
        }
        return -1;  // Return -1 if key doesn't exist
    }
    
    void put(int key, int value) {
        if(map.find(key) != map.end()) {
            Node* node = map[key];
            remove(node);            // Remove the old node if it exists
        }

        // Create a new node
        Node* node = new Node(key, value);
        map[key] = node;            // Add it to the map
        insertAtHead(node);         // Insert it at the head (most recently used)

        if(map.size() > capacity) {
            Node* nodeToRemove = tail->prev;  // The LRU node is right before the tail
            remove(nodeToRemove);
            map.erase(nodeToRemove->key);     // Remove the LRU node from the map
            delete nodeToRemove;              // Free memory
        }
    }

    void insertAtHead(Node* node) {
        Node* temp = head->next;  // Store the node currently after head
        
        // Insert the new node between head and temp
        head->next = node;
        node->prev = head;   // Set the previous node of new node to head
        node->next = temp;   // Set the next node of new node to the old first node
        temp->prev = node;   // Set the previous node of the old first node to new node
    }

    void remove(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;   // Update the next pointer of the previous node
        nextNode->prev = prevNode;   // Update the previous pointer of the next node
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
