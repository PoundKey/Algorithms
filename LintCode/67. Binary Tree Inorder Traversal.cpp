class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: Inorder in vector which contains node values.
     */
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res(0);
        if (root == NULL) return res;
        traverse(root, res);
        return res;
    }
    
    void traverse(TreeNode* root,  vector<int>& res) {
        if (root == NULL) return;
        traverse(root->left, res);
        res.push_back(root->val);
        traverse(root->right, res);
    }
};
