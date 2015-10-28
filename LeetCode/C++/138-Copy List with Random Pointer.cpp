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
        RandomListNode *dummy = new RandomListNode(0);
        RandomListNode *p = dummy, *it = head;
        unordered_map<RandomListNode*, RandomListNode*> dic;
        while (it) {
            RandomListNode* node = new RandomListNode(it->label);
            node->random = it->random;
            dic[it] = node;
            p->next = node;
            p = p->next;
            it = it->next;
        }
        
        it = dummy->next;
        while (it) {
            if (it->random) {
                it->random = dic[it->random];
            }
            it = it->next;
        }
        
        return dummy->next;
    }
};
