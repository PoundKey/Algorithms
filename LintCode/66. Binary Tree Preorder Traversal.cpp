class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        DFS(root, res);
        return res;
    }
    void DFS(TreeNode* root, vector<int>& res) {
        if (root == NULL) return;
        res.push_back(root->val);
        DFS(root->left, res);
        DFS(root->right, res);
    }
};
