// Thoughts: Classic floyd two pointers problem
// Set middle on the left side. e.g., [1, 2, 3, 4] => mid: 2
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
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return false;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                return true;
        }  
        
      	return false;
    }
};

//Set middle on the right side. e.g., [1, 2, 3, 4] => mid: 3
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                return true;
        }
        
        return false;
    }
};