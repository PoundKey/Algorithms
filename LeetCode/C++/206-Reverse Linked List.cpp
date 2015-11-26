// Thoughts: Iteration O(n)
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

//Thoughts: Recursion wihtout helper
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* node = reverseList(head->next);
        head->next->next  = head;
        head->next = NULL;
        return node;
    }
};

