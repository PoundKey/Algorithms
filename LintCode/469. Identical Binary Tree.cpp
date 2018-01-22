// 1. in order for a tree to be identical, it's subtrees must be identical
// 2. what if the subtrees are already identical?
// 3. if the node values are also equal, the trees are identical
class Solution {
public:
    bool isIdentical(TreeNode* a, TreeNode* b) {
        if (a == NULL && b == NULL) return true;
        if (a == NULL || b == NULL) return false;
        bool left = isIdentical(a->left, b->left);
        if (!left) return false;
        bool right = isIdentical(a->right, b->right);
        if (!right) return false;
        return (a->val != b->val)
    }
};
