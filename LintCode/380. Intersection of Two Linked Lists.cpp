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
       stack<ListNode*> s1;
       stack<ListNode*> s2;
       while (headA) {
           s1.push(headA);
           headA = headA->next;
       }
       while (headB) {
           s2.push(headB);
           headB = headB->next;
       }
       ListNode* res = NULL;
       while (!s1.empty() && !s2.empty()) {
           if (s1.top() == s2.top()) {
               res = s1.top();
               s1.pop();
               s2.pop();
           } else {
               return res;
           }
       }
       return res;
    }
};
