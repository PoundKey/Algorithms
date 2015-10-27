// Thoughts: 
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode *p = head;
        while (p->next) {
            if (p->val == p->next->val) {
                p->next = p->next->next;
            } else {
                p = p->next;
            }
        }
        return head;
    }
};


// Recursive way: DFS
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = DFS(head);
        return dummy->next;
    }
    
    ListNode* DFS(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* next = DFS(head->next);
        head->next = next;
        return (head->val == next->val) ? next : head;
    }
};