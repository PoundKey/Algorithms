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

// Anohter time-efficient code
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return DFS(root) == -1 ? false : true;
    }
    
    int DFS(TreeNode* root) {
        if (!root) return 0;
        int leftDepth = DFS(root->left);
        if (leftDepth == -1) return -1;
        int rightDepth = DFS(root->right);
        if (rightDepth == -1) return -1;
        if (abs(leftDepth - rightDepth) > 1) return -1;
        return max(leftDepth, rightDepth) + 1;
    }
};
