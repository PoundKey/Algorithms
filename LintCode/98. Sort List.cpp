class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: You should return the head of the sorted linked list,
                    using constant space complexity.
     */
    ListNode *sortList(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* left = head;
        ListNode* right = slow->next;
        slow->next = NULL;
        
        left = sortList(left);
        right = sortList(right);
        return merge(left, right);
    }
    
    ListNode* merge(ListNode* n1, ListNode* n2) {
        if (n1 == NULL && n2 == NULL) return NULL;
        ListNode dummy;
        ListNode* prev = &dummy;
        
        while (n1 || n2) {
            if (n1 && (n2 == NULL || n1->val <= n2->val)) {
                prev->next = n1;
                n1 = n1->next;
            } else {
                prev->next = n2;
                n2 = n2->next;
            }
            prev = prev->next;
        }
        return dummy.next;
    }
};
