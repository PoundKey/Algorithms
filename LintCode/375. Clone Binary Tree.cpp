class Solution {
public:
    /**
     * @param root: The root of binary tree
     * @return root of new tree
     */
    TreeNode* cloneTree(TreeNode *root) {
        if (root == NULL) return NULL;
        TreeNode* node = new TreeNode(root->val);
        TreeNode* leftNode = cloneTree(root->left);
        TreeNode* rightNode = cloneTree(root->right);
        node->left = leftNode;
        node->right = rightNode;
        return node;
    }
};
