class Solution {
public:
    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void invertBinaryTree(TreeNode *root) {
        if (root == NULL) return;
        invertBinaryTree(root->left);
        invertBinaryTree(root->right);
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
};
