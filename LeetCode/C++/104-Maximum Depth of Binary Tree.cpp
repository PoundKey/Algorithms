// Thoughts: Recursion on left and right side of the tree to find the height of its subtree
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
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        return traverse(root);
    }
    
    int traverse(TreeNode* root) {
        if (root == NULL) return -1;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left, right) + 1;      
    }
};
