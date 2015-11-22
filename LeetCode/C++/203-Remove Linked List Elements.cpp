
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return NULL;
        head->next = removeElements(head->next, val);
        return (head->val == val) ? head->next : head;
    }
};

// Solution v2: use a dummy node, with dummy->next = head
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* p = dummy, *node;
        while (p->next) {
            node = p->next;
            if (node->val == val) {
                p->next = node->next;
                delete node;
                node = NULL;
            } else {
                p = p->next;
            }
        }
        return dummy->next;
    }
};