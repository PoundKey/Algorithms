// Thoughts: Slide the start variable when dulplicate occurs.
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
        if (head == NULL || head->next == NULL) return head;
        ListNode *dummy = new ListNode(0);
        ListNode *prev = dummy, *start = head;
        while (start && start->next) {
            if (start->val != start->next->val) {
                 prev->next = start;
                 prev = prev->next;
                 start = start->next;
            } else {
                int val = start->val;
                while (start && start->val == val) {
                    start = start->next;
                }
            }
            
        }
        prev->next = start;
        return dummy->next;
    }
};
