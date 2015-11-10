// Thoughts: Total length we need to reverse: m - n + 1;
// total node we need to reverse inside of while loop: m - n + 1 - 1 = m - n
// starting from the m + 1, end when m - n = 0
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head) return NULL;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* start = dummy;
        for (int i = 0; i < m - 1; i++) {
            start = start->next;
        }
        
        ListNode* prev = start->next, *curr = prev->next;
        int step = n - m;
        while (step) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            step--;
        }
        start->next->next = curr;
        start->next = prev;
        return dummy->next;
    }
};