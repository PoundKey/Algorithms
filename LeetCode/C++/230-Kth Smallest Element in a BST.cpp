// Thoughts: In-order traversal, O(n)
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int result;
        traverse(root, k, count, result);
        return result;
    }
    
    void traverse(TreeNode* root, int k, int& count, int& res) {
        if (root == NULL) return;
        traverse(root->left, k, count, res);
        count++;
        if (count == k) {
            res = root->val;
            return;
        }
        traverse(root->right, k, count, res);
    }
};

