class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @param m: The start position need to reverse.
     * @param n: The end position need to reverse.
     * @return: The new head of partial reversed linked list.
     */
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (head == NULL || head->next == NULL) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* p = &dummy;
        
        int count = n - m;
        while (m > 1) {
            p = p->next;
            m--;
        }
        ListNode* prev = p->next, *curr = prev->next;
        while (count != 0) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count--;
        }
        p->next->next = curr;
        p->next = prev;
        return dummy.next;
    }
};
