class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == NULL || n == 0) return NULL;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy, *slow = head, *fast = head;
        while (n) {
            fast = fast->next;
            n--;
        }
        while (fast) {
            fast = fast->next;
            prev = slow;
            slow = slow->next;
        }
        ListNode* temp = slow;
        prev->next = slow->next;
        delete temp;
        return dummy.next;
    }
    ListNode *removeNthFromEndAlt(ListNode *head, int n) {
        if (head == NULL || n == 0) return NULL;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* p = &dummy;
        int m = 0;
        while (head) {
            m++;
            head = head->next;
        }
        
        for (int i = 0; i < m - n; i++) p = p->next;
        ListNode* next = p->next, *nextNext = next->next;
        p->next = nextNext;
        delete next;
        return dummy.next;
    }
};
