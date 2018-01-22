class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        if (root == NULL) return true;
        return maxHeight(root) == INT_MIN ? false : true;
    }
    
    int maxHeight(TreeNode* root)
    {
        if (root == NULL) return -1;
        int maxLeft = maxHeight(root->left);
        if (maxLeft == INT_MIN) return INT_MIN;
        int maxRight = maxHeight(root->right);
        if (maxRight == INT_MIN) return INT_MIN;
        
        int diff = abs(maxRight - maxLeft);
        if (diff > 1) return INT_MIN;
        return max(maxLeft, maxRight) + 1;
    }
};
