class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) return NULL;
        RandomListNode* iter = head;
        map<RandomListNode*, RandomListNode*> map;
        while (iter) {
            int label = iter->label;
            RandomListNode* node = new RandomListNode(label);
            node->next = iter->next;
            node->random = iter->random;
            map[iter] = node;
            iter = iter->next;
        }
        
        RandomListNode* headCopy = map[head];
        while (headCopy) {
            headCopy->next = map[headCopy->next];
            headCopy = headCopy->next;
        }
        return map[head];
    }
};
