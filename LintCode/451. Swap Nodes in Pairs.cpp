class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* next = head->next, *nextNext = next->next;
        next->next = head;
        head->next = swapPairs(nextNext);
        return next;
    }
    
    ListNode* swapPairsIter(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode dummy(0, head);
        ListNode* prev = &dummy;
        
        while (head && head->next)
        {
            ListNode* next = head->next;
            ListNode* nextNext = next->next;
            next->next = head;
            prev->next = next;
            prev = head;
            head->next = nextNext;
            head = nextNext;
        }
        return dummy.next;
    }    
};
