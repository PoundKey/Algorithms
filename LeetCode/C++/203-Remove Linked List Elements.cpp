/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return NULL;
        head->next = removeElements(head->next, val);
        return (head->val == val) ? head->next : head;
    }
};

// Solution v2: use a dummy node, with dnode->next = head
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dnode(0);
        dnode.next = head;
        ListNode *it = &dnode;
        while (it->next) {
            if (it->next->val == val) {
                it->next = it->next->next;
            } else {
               it = it->next; 
            }
            
        }
        
        return dnode.next;
    }
};