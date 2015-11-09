// Thoughts: 
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return NULL;
        return build(head, NULL);
    }
    
    TreeNode* build(ListNode* start, ListNode* end) {
        if (start == end) return NULL; //out of scope.
        ListNode *slow = start, *fast = start;
        while (fast != end && fast->next != end) {
            fast = fast->next->next;
            slow = slow->next;
        }
        TreeNode* node = new TreeNode(slow->val);
        node->left = build(start, slow);
        node->right = build(slow->next, end);
        return node;
    }
};
