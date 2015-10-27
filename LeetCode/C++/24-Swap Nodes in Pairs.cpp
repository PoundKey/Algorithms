// Thoughts: Recursive version, like a breeze.
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* next = head->next;
        ListNode* node = next->next;
        next->next = head;
        head->next = swapPairs(node);
        return next;
    }
};

// Thoughts: Iterative Version, constant space as required.
//  use prev and curr as the variable name
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy, *curr = head;
        
        while (curr && curr->next) {
            prev->next = curr->next;
            curr->next = curr->next->next;
            prev->next->next = curr;
            prev = curr;
            curr = curr->next;
        }
        return dummy->next;
    }
};
 
