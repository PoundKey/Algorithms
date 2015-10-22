// Thoughts: Nothing much to say, just IO Recursion.
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == q) return true; // NULL check
        if (p == NULL || q == NULL) return false;
        bool leftCheck = isSameTree(p->left, q->left);
        bool rightCheck = isSameTree(p->right, q->right);
        return (p->val == q->val) && leftCheck && rightCheck;
    }
};
