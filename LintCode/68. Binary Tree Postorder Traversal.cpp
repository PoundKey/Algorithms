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
    // Iteratively, two stacks approach
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        if (root == NULL) return res;
        stack<TreeNode*> s1, s2;
        s1.push(root);
        while (!s1.empty())
        {
            TreeNode* node = s1.top();
            s1.pop();
            s2.push(node);
            if (node->left) s1.push(node->left);
            if (node->right) s1.push(node->right);
        }
        while (!s2.empty())
        {
            TreeNode* node = s2.top();
            s2.pop();
            res.push_back(node->val);
        }
        return res;
    } 
};
