class Solution {
public:
    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void flatten(TreeNode *root) {
        if (root == NULL) return;
        DFS(root);
    }
    
    TreeNode* DFS(TreeNode* root) {
        if (root == NULL) return NULL;
        TreeNode* leftTail = DFS(root->left);
        TreeNode* rightTail = DFS(root->right);
        if (leftTail) {
            TreeNode* right = root->right;
            root->right = root->left;
            root->left = NULL;
            leftTail->right = right;
        }
        if (rightTail) return rightTail;
        if (leftTail) return leftTail;
        return root;
    }
};
