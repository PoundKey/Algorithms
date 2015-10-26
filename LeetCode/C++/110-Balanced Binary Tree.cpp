// Thoughts: A binary tree is balanced is and only if its root is balanced, 
// and its subtrees are balanced.
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
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        if (abs(left - right) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
    
    int getHeight(TreeNode* root) {
        if (root == NULL) return -1;
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        return max(left, right) + 1;
    }
};
