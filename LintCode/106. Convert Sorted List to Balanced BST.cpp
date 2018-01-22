class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == NULL) return NULL;
        ListNode* prev = NULL, *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode* root = new TreeNode(slow->val);
        ListNode* left = head;
        ListNode* right = slow->next;
        if (prev) prev->next = NULL;
        root->left = (left == slow ? NULL : sortedListToBST(left));
        root->right = sortedListToBST(right);
        return root;
    }
};
