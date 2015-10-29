// Thoughts: 
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || k == 0) return head;
        int n = 1;
        ListNode* p = head;
        while (p->next) {
            n++;
            p = p->next;
        }
        int m = n - k % n;
        p->next = head;
 
        for (int i = 0; i < m; i++) {
            p = p->next;
        }
        ListNode* res = p->next;
        p->next = NULL;
        return res;
    }
};
