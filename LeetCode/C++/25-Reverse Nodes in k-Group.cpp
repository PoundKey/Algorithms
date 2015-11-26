// Thoughts: Prefer doing it recursively. Idea is simple, use a helper function
// to find the last node (end) within the range of total k nodes.
// record the node after end node as endNext.
// Look out for siutation where k > 1 and head == NULL, should do nothing and return head.
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head->next || k == 1) return head;
        ListNode* end = findEnd(head, k);
        if (end == NULL) return head;
        ListNode* endNext = end->next;
        ListNode *prev = head, *curr = head->next;
        while (curr != endNext) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head->next = reverseKGroup(endNext, k);
        return end;
    }
    
    ListNode* findEnd(ListNode* head, int count) {
        if (count == 1) return head;
        if (head == NULL) return NULL;
        return findEnd(head->next, count - 1);
    }
};