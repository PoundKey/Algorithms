// Thoughts: Situations to notice
// 1: if any of the linklist is null, e.g., L1: NULL, L2: 1->2  return: 1->2
// 2: if the final linklist is longer than any of the two:
// L1: 2->2, L2: 9->9, return: 1->2->1
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dnode = new ListNode(0);
        ListNode* p = dnode;
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
            ListNode* node = new ListNode(carry % 10);
            carry = carry / 10;
            p->next = node;
            p = p->next;
        }
        return dnode->next;
    }
};

// Recursive fashion 1
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dnode = new ListNode(0);
        addHelper(dnode, 0, l1, l2);
        return dnode->next;
    }
    
    void addHelper(ListNode* root, int carry, ListNode* l1, ListNode* l2) {
        if (l1 == NULL && l2 == NULL && carry == 0) return;
        if (l1) { 
            carry += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            carry += l2->val;
            l2 = l2->next;
        }
        ListNode* node  = new ListNode(carry % 10);
        carry /= 10;
        root->next = node;
        addHelper(root->next, carry, l1, l2);
    }
};

// Recursion fasion 2
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dnode = new ListNode(0);
        dnode->next = addHelper(0, l1, l2);
        return dnode->next;
    }
    
    ListNode* addHelper(int carry, ListNode* l1, ListNode* l2) {
        if (l1 == NULL && l2 == NULL && carry == 0) return NULL;
        if (l1) { 
            carry += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            carry += l2->val;
            l2 = l2->next;
        }
        ListNode* node  = new ListNode(carry % 10);
        carry /= 10;
        node->next = addHelper(carry, l1, l2);
        return node;
    }
};