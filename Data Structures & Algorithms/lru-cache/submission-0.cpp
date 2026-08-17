class Node {
    public:
        int key;
        int val;
        Node* next;
        Node* prev;

        Node() : key(-1), val(-1), next(nullptr), prev(nullptr) {}
        Node(int key, int val) : key(key), val(val), next(nullptr), prev(nullptr) {}
};

class LRUCache {
public:
    unordered_map<int, Node*> mp;
    int cap;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        cap = capacity;
        head = new Node();
        tail = new Node();

        head->next = tail;
        tail->prev = head;
    };

    void deleteNode(Node* node) {
        Node* prev = node->prev;
        node->prev->next = node->next;
        node->next->prev = prev;
        return;
    }

    void insert(Node* node) {
        node->next = head->next;
        node->next->prev = node;
        head->next = node;
        node->prev = head;
        return;
    }
    
    int get(int key) {
        if (!mp.count(key))
            return -1;

        Node* node = mp[key];
        deleteNode(node);
        insert(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if (mp.count(key)) {
            Node* node = mp[key];
            node->val = value;
            deleteNode(node);
            insert(node);
        }

        else {
            if (mp.size() == cap) {
                mp.erase(tail->prev->key);
                deleteNode(tail->prev);
            }

            Node* node = new Node(key, value);
            insert(node);
            mp[key] = node;
        }
    }
};
