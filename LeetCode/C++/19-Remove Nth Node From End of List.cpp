// Thoughts: initialize two pointers, slow and fast, let the fast pointer move
// n steps, and then move both slow and fast pointers until the fast pointer reaches
// NULL. At this rate the slow pointer is the target node. Add a prev node to make things easier.
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return NULL;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy, *slow = head, *fast = head;
        while (n) {
            fast = fast->next;
            n--;
        }
        while (fast) {
            fast = fast->next;
            prev = slow;
            slow = slow->next;
        }
        
        prev->next = slow->next;
        return dummy->next;
    }
};

