// Thoughts: we only take one side of the tree from each subtree.
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
    int maxPathSum(TreeNode* root) {
        int maxVal = INT_MIN;
        findMax(root, maxVal);
        return maxVal;
    }
    
    int findMax(TreeNode* root, int& maxVal) {
        if (!root) return 0;
        int left = findMax(root->left, maxVal);
        int right = findMax(root->right, maxVal);
        maxVal = max(maxVal, left + right + root->val);
        int res = root->val + max(left, right);
        return res > 0 ? res : 0;
    }
};
