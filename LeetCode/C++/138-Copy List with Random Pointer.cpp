// Thoughts: Review the concept of deep copy
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return NULL;
        RandomListNode* dummy = new RandomListNode(0), *p = dummy;
        unordered_map<RandomListNode*, RandomListNode*> ht;
        
        while (head) {
            RandomListNode* node = new RandomListNode(head->label);
            node->random = head->random;
            ht[head] = node;
            p->next = node;
            p = p->next;
            head = head->next;
        }
        
        p = dummy->next;
        while (p) {
            if (p->random) {
                p->random = ht[p->random];
            }
            p = p->next;
        }
        return dummy->next;
    }
};
