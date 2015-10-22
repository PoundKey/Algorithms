// Thoughts: This question is a bit tricky. For example:
// [] => 0, [1] => 1, [1, 2] => 2, [1, 2, 3] => 3
// Therefore it's a bit different from Q104
// Key is to define a leaft node: (leaf->left == NULL) && (left->right == NULL)
// Basically, it's left node counting game, with the shortest path.

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
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        if (left == 0 && right == 0) return 1;
        if (left == 0) left = INT_MAX;
        if (right == 0) right = INT_MAX;
        return min(left, right) + 1;
    }
};