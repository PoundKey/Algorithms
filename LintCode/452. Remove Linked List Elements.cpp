class Solution {
public:
    /**
     * @param head a ListNode
     * @param val an integer
     * @return a ListNode
     */
    ListNode *removeElements(ListNode *head, int val) {
        if (head == NULL) return NULL;
        ListNode dummy(0, head);
        ListNode* prev = &dummy;
        ListNode* curr = head;
        while (curr != NULL)
        {
            if (curr->val == val) 
            {
                ListNode* next = curr->next;
                prev->next = next;
                delete curr;
                curr = next;
            } 
            else 
            {
                prev = curr;
                curr = curr->next;
            }
        }
        return dummy.next;
    }
};
