class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: Postorder in vector which contains node values.
     */
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        DFS(root, res);
        return res;
    }
    void DFS(TreeNode* root, vector<int>& res) {
        if (root == NULL) return;
        DFS(root->left, res);
        DFS(root->right, res);
        res.push_back(root->val);
    }
};
