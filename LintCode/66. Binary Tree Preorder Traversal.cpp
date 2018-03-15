class Solution {
public:
    // iterative
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode*> stack;
        TreeNode* node = root;
        while (!stack.empty() || node)
        {
            if (node)
            {
                res.push_back(node->val);
                if (node->right) stack.push(node->right);
                node = node->left;
            }
            else
            {
                node = stack.top();
                stack.pop();
            }
        }
        return res;
    }
    
    // recursive
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
