// Thoughts: Use two pointers
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy1 = new ListNode(0), *dummy2 = new ListNode(0);
        ListNode* left = dummy1, *right = dummy2;
        
        while (head) {
            if (head->val < x) {
                left->next = head;
                left = left->next;
            } else {
                right->next = head;
                right = right->next;
            }
            head = head->next;
        }
        left->next = dummy2->next;
        right->next = NULL;
        
        return dummy1->next;
    }
};
