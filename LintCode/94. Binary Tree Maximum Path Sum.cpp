class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxVal = INT_MIN;
    int maxPathSum(TreeNode *root) {
        if (root == NULL) return 0;
        findMax(root);
        return maxVal;
    }
    
    int findMax(TreeNode *root) {
        if (root == NULL) return 0;
        int leftMax = findMax(root->left);
        int rightMax = findMax(root->right);
        maxVal = max(maxVal, leftMax + rightMax + root->val);
        int res = root->val + max(leftMax, rightMax);
        if (res > 0) {
            return res;
        } else {
            return 0;
        }
    }
};
