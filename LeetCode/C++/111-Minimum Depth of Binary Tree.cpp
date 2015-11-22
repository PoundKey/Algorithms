// When there is only one root element, return 1.
// if its left subtree is empty, return 1 + minDepth of the right subtree
// vice versa if the right subtree is empty, return 1 + minDepth of the left subtree.
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left) return minDepth(root->right) + 1;
        if (!root->right) return minDepth(root->left) + 1;
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};