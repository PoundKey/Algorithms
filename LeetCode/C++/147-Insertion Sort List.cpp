// Thoughts: Iterative Fasion
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 

// Thoughts:  Recursive Fasion
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* next = insertionSortList(head->next);
        if (head->val <= next->val) {
            head->next = next;
            return head;
        } else {
            ListNode *prev = next;
            while (prev->next && head->val > prev->next->val) {
                prev = prev->next;
            }
            head->next = prev->next;
            prev->next = head;
            return next;
        }
    }
};

