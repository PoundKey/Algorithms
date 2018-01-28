struct Node 
{
    int key;
    int value;
    Node* prev;
    Node* next;
    Node(int in_key, int in_value, Node* in_prev = NULL, Node* in_next = NULL) :
    key(in_key), value(in_value), prev(in_prev), next(in_next)
    {
        
    }
};

class LRUCache {
public:
    int m_capacity;
    unordered_map<int, Node*> cacheMap;
    Node* head;
    Node* tail;
    /*
    * @param capacity: An integer
    */LRUCache(int capacity) : 
        m_capacity(capacity), head(NULL), tail(NULL) 
    {
        
    }

    void updateCache(Node* node)
    {
        if (node == NULL || node == tail) return;
        
        if (node == head)
        {
            head = node->next;
            head->prev = NULL;
        }
        else
        {
            // node is in the middle of the linkedlist
            Node* prevNode = node->prev;
            Node* nextNode = node->next;
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
        }
        tail->next = node;
        node->prev = tail;
        node->next = NULL;
        tail = node;
    }
    /*
     * @param key: An integer
     * @return: An integer
     */
    int get(int key) {
        // 1. access the cached items map
        // 2. update the key as the most recent used cache
        if (!cacheMap.count(key)) return -1;
        Node* item = cacheMap[key];
        updateCache(item);
        return item->value;
    }
    
    bool isFull()
    {
        return cacheMap.size() >= m_capacity;
    }
    /*
     * @param key: An integer
     * @param value: An integer
     * @return: nothing
     */
    void set(int key, int value) {
        if (m_capacity <= 0) return;
        if (cacheMap.count(key))
        {
            cacheMap[key]->value = value;
            // update an existing cache also makes it most recently used
            updateCache(cacheMap[key]); 
            return;
        }
        // 1. if LRUCache is full
        //  1.1 remove the least recent used cache - head
        //  1.2 insert key and value to the cache, make it the most recent used cache
        //  1.3 update the cache map
        // 2. if LRUCache is not full
        //  2.1 insert into the cache, and make it most recent used cache
        //  2.2 update the cache map and capacity
        if (isFull())
        {
            Node* node = new Node(key, value);
            Node* temp = head;
            if (head == tail)
            {
                // single item, replace it with the newly created node
                head = node;
                tail = node;
            }
            else
            {
                head = head->next;
                head->prev = NULL;
                tail->next = node;
                node->prev = tail;
                tail = node;
            }
            cacheMap[key] = node;
            cacheMap.erase(temp->key);
            delete temp;
        }
        else
        {
            Node* node = new Node(key, value);
            if (cacheMap.empty())
            {
                head = node;
                tail = node;
            }
            else
            {
                // make the node the most recent cache (tail)
               tail->next = node;
               node->prev = tail;
               tail = node;
            }
            cacheMap[key] = node;
        }
    }
};
