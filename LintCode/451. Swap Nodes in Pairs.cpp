class Solution {
public:
    /**
     * @param head a ListNode
     * @return a ListNode
     */
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        
        ListNode* next = head->next, *nextNext = next->next;
        next->next = head;
        head->next = swapPairs(nextNext);
        return next;
    }
};
