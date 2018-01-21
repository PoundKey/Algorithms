// singly linked list, could only delete the next, so replicate it first
class Solution {
public:
    /**
     * @param node: a node in the list should be deleted
     * @return: nothing
     */
    void deleteNode(ListNode *node) {
        if (node == NULL || node->next == NULL) {
            delete node;
            return;
        }
        
        ListNode* next = node->next;
        node->val = next->val;
        node->next = next->next;
        delete next;
    }
};
