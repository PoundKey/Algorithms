/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* next = deleteDuplicates(head->next);
        if (head->val == next->val) {
            delete head;
            return next;
        } else {
            head->next = next;
            return head;
        }
    }
    
    ListNode *deleteDuplicatesIter(ListNode *head) {
        if (head == NULL) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* cur = dummy.next;
        while (cur->next != NULL) {
            ListNode* next = cur->next;
            if (cur->val == next->val) {
                cur->next = next->next;
                delete next;
            } else {
                cur = next;
            }
        }
        return dummy.next;
    }
};
