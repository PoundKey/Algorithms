// Thoughts: 
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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) return false;
        if (root->val == sum && root->left == NULL && root->right== NULL) return true;
        bool leftCheck = hasPathSum(root->left, sum-(root->val));
        bool rightCheck = hasPathSum(root->right, sum-(root->val));
        return leftCheck || rightCheck;
    }
};
