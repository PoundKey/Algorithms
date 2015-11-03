// Thoughts: Use a stack to reverse the list.
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
    bool isPalindrome(ListNode* head) {
        stack<ListNode*> s;
        ListNode* p = head;
        while (p) {
            s.push(p);
            p = p->next;
        }
        p = head;
        while (p) {
            if (s.top()->val != p->val) return false;
            s.pop();
            p = p->next;
        }
        return true;
    }
};

//Thoguts, O(1) space: find the middle value of the Linkedlist, reverse the
//second half, and compare with the first half.
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode* p = head;
        ListNode* mid = findMiddle(head);
        ListNode* left = reverse(mid->next);
        ListNode* q = left;
        while (q) {
            if (q->val != p->val) {
                mid->next = reverse(left);
                return false; 
            }
            q = q->next;
            p = p->next;
        }
        mid->next = reverse(left);
        return true;
    }
    
    ListNode* findMiddle(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    ListNode* reverse(ListNode* head) {
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

//Thoughts: use the call stack as the container and do the recursion.
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode* p = head;
        return helper(head, p);
    }
    bool helper(ListNode*& head, ListNode* p) {
        bool res = true;
        if (p->next) {
             res = helper(head, p->next);
        } 
        if (!res) return false;
        res = head->val == p->val;
        head = head->next;
        return res;
    }
};