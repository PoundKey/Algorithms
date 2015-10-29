// Thoughts:  1. Find the the mid pointer of the list, divide the list into left the right part
// 2. Reverse the right part
// 3. Alternately merge the left and right part

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
    void reorderList(ListNode* head) {
        if (head == NULL) return;
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = reverse(slow->next);
        slow->next = NULL;
        merge(head, fast);
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
     
     void merge(ListNode* l1, ListNode* l2) {
         if (l1 == NULL || l2 == NULL) return;
         ListNode* next = l1->next;
         l1->next = l2;
         merge(l2, next);
     }
};

