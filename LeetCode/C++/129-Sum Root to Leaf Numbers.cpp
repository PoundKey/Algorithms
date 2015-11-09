// Thoughts: Typical DFS
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return DFS(root, 0);
    }
    
    int DFS(TreeNode* root, int curr) {
        if (!root) return 0;
        int val = curr * 10 + root->val;
        if (!root->left && !root->right) {
            return val;
        }
        return DFS(root->left, val) + DFS(root->right, val);
    }
};
