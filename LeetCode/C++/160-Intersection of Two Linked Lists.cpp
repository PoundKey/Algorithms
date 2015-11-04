// Thoughts: 
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        ListNode *p = headA, *q = headB;
        int a = 0, b = 0;
        while (p->next) {
            a++;
            p = p->next;
        }
        while (q->next) {
            b++;
            q = q->next;
        }
        
        p = headA;
        q = headB;
        if (a > b) {
            int n = a - b;
            while (n) {
                p = p->next;
                n--;
            }
        } else {
            int n = b - a;
            while (n) {
                q = q->next;
                n--;
            }
        }
        
        while (p && q) {
            if (p == q) return p;
            p = p->next;
            q = q->next;
        }
        
        return NULL;
    }
};
