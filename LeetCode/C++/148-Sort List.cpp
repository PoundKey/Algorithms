// Thoughts: Mergesort
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
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        fast = slow->next;
        slow->next = NULL;
        
        ListNode* left = sortList(head);
        ListNode* right = sortList(fast);
        return merge(left, right);
    }
    
    ListNode* merge(ListNode* first, ListNode* second) {
        ListNode* dummy = new ListNode(0);
        ListNode* p = dummy;
        while (first || second) {
            if (first && second) {
                if (first->val <= second->val) {
                    p->next = first;
                    first = first->next;
                } else {
                    p->next = second;
                    second = second->next;
                }
                p = p->next;
            } else if (first) {
                p->next = first;
                break;
            } else if (second) {
                p->next = second;
                break;
            }
        }
        return dummy->next;
    }
};
