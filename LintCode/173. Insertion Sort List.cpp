class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: The head of linked list.
     */
    ListNode *insertionSortList(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* node = insertionSortList(head->next);
        if (head->val > node->val) {
            ListNode* prev = node;
            ListNode* next = prev->next;
            while (next && head->val > next->val) {
                prev = next;
                next = next->next;
            }
            prev->next = head;
            head->next = next;
            return node;
        } else {
            head->next = node;
            return head;
        }
    }
};
