// Thoughts: Iteratively compare two lists
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *curr = dummy;
        while (l1 || l2) {
            if (l1 && l2) {
                if (l1->val < l2->val) {
                    curr->next = l1;
                    l1 = l1->next;
                } else {
                    curr->next = l2;
                    l2 = l2->next;
                }
                curr = curr->next;
            } else if (l1) {
                curr->next = l1;
                break;
            } else {
                curr->next = l2;
                break;
            }
        }
        return dummy->next;
    }
};

// Again, do it recursively
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL && l2 == NULL) return NULL;
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};