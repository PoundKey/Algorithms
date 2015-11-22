// Thoughts: In-order traversal: left, root, and right. prev comes from the left,
// therefore prev->val < root->val
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

// Same version, but with prev extracted as a instance variable.
class Solution {
private:
    TreeNode* prev = NULL;
public:
    bool isValidBST(TreeNode* root) {
        return validate(root);
    }
    bool validate(TreeNode* root) {
        if (!root) return true;
        bool left = validate(root->left);
        if (!left) return false;
        if (prev && prev->val >= root->val) return false;
        prev = root;
        return validate(root->right);
    }
};


// Thoughts: ...
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, NULL, NULL);
    }
    bool validate(TreeNode* root, int* low, int* high) {
        if (!root) return true;
        bool res = (!low || root->val > *low) && (!high || root->val < *high)
                   && validate(root->left, low, &(root->val)) 
                   && validate(root->right, &(root->val), high);
        return res ;
    }
};

