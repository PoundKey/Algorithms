// Thoughts: Can also use method to check if a binary tree is complete
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return DFS(root->left, root->right);
    }
    bool DFS(TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL) return true;
        if (left == NULL || right == NULL || left->val != right->val) return false;
        bool leftCheck = DFS(left->left, right->right);
        bool rightCheck = DFS(left->right, right->left);
        return leftCheck && rightCheck;
    }
};
