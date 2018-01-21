// 1. starts with the root, see if it's identical, using AND gate
// 2. if root is not identical, compare the left and right subtree, using OR gate

class Solution {
public:
    /**
     * @param T1, T2: The roots of binary tree.
     * @return: True if T2 is a subtree of T1, or false.
     */
    bool isSubtree(TreeNode *T1, TreeNode *T2) {
        if (T2 == NULL) return true;
        if (T1 == NULL) return false;
        if (IsIdentical(T1, T2)) return true;
        return isSubtree(T1->left, T2) || isSubtree(T1->right, T2);
    }
    bool IsIdentical(TreeNode* T1, TreeNode* T2) {
        if (T1 == NULL && T2 == NULL) return true;
        if (T1 == NULL || T2 == NULL) return false;
        if (T1->val != T2->val) return false;
        return IsIdentical(T1->left, T2->left) &&
        IsIdentical(T1->right, T2->right);
        
    }
};
