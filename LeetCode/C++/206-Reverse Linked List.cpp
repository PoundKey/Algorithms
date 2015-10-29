// Thoughts: Iteration O(n)
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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return head;
        ListNode* prev = NULL;
        while (head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
     }

};

// Thoughts: Recursion
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return head;
        return DFS(NULL, head);
     }
    ListNode* DFS(ListNode* prev, ListNode* head) {
        ListNode* next = head->next;
        head->next = prev;
        return next == NULL ? head : DFS(head, next);
    }
};

