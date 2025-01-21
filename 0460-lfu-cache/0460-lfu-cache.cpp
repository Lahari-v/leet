class Node {
public:
    int key, value, cnt;
    Node* prev;
    Node* next;
    Node(int key, int value) {
        this->key = key;
        this->value = value;
        cnt = 1;
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
        size = 0;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    void insert(Node* node) {
        Node* temp = head->next;
        head->next = node;
        node->prev = head;
        node->next = temp;
        temp->prev = node;
        size++;
    }

    void remove(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        size--;
    }
};

class LFUCache {
public:
    int maxsizeCache, currsize, minfreq;
    map<int, Node*> keyNode;
    map<int, List*> freqList; 
    LFUCache(int capacity) {
        maxsizeCache = capacity;
        minfreq = 0;
        currsize = 0;
    }
    
    int get(int key) {
        if(keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];
            int val = node->value;
            updateFreqlist(node);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxsizeCache == 0)
            return;
        if(keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];
            node->value = value;
            updateFreqlist(node);
        }
        else {
            if(maxsizeCache == currsize) {
                List* list = freqList[minfreq];
                keyNode.erase(list->tail->prev->key);
                freqList[minfreq]->remove(list->tail->prev);
                currsize--;
            }
            currsize++;
            minfreq = 1;
            List* list = new List();
            if(freqList.find(minfreq) != freqList.end()) 
                list = freqList[minfreq];
            Node* node = new Node(key, value);
            list->insert(node);
            keyNode[key] = node;
            freqList[minfreq] = list;
        }
    }

    void updateFreqlist(Node* node) {
        keyNode.erase(node->key);
        freqList[node->cnt]->remove(node);
        if(minfreq == node->cnt && freqList[node->cnt]->size == 0) {
            minfreq++;
        }
        List* nextHigherFreqList = new List();
        if(freqList.find(node->cnt + 1) != freqList.end()) {
            nextHigherFreqList = freqList[node->cnt + 1];
        }
        node->cnt++;
        nextHigherFreqList->insert(node);
        keyNode[node->key] = node;
        freqList[node->cnt] = nextHigherFreqList;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */