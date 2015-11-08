// Thoughts: In-order traversal
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL; 
        return validate(root, prev);
    }
    bool validate(TreeNode* root, TreeNode*& prev) {
        if (root) {
            if (!validate(root->left, prev)) return false;
            if (prev && root->val <= prev->val) return false;
            prev = root;
            return validate(root->right, prev);
        }
        return true;        
    }
};
