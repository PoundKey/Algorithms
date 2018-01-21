/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2 
     */
    ListNode *addLists(ListNode *l1, ListNode *l2) {
        ListNode dummy;
        ListNode* prev = &dummy;
        int carry = 0;
        while (l1 || l2 || carry) {
            if (l1) {
                carry += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                carry += l2->val;
                l2 = l2->next;
            }
            int val = carry % 10;
            carry = carry > 9 ? 1 : 0;
            ListNode* node = new ListNode(val, NULL);
            prev->next = node;
            prev = node;
        }
        if (carry) {
            prev->next = new ListNode(1, NULL);
        }
        return dummy.next;
    }
};
