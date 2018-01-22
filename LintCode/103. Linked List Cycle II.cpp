class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: The node where the cycle begins. 
     *           if there is no cycle, return null
     */
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return NULL;
        set<ListNode*> set;
        while (head) {
            if (set.count(head)) return head;
            else set.insert(head);
            head = head->next;
        }
        return NULL;
    }
};
