class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    TreeNode* prev = NULL;
    bool isValidBST(TreeNode *root) {
        if (root == NULL) return true;
        if (!isValidBST(root->left)) return false;
        if (prev && prev->val >= root->val) return false;
        prev = root;
        return isValidBST(root->right);
    }
};
