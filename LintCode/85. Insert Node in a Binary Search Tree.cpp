class Solution {
public:
    /**
     * @param root: The root of the binary search tree.
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode* insertNode(TreeNode* root, TreeNode* node) {
        if (root == NULL) return node;
        if (root->val > node->val) {
            root->left = insertNode(root->left, node);
        } 
        else 
        {
            root->right = insertNode(root->right, node);
        }
        return root;
    }
};
