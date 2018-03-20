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
    
    // Iteratively
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res(0);
        if (root == NULL) return res;
        TreeNode* node = root;
        stack<TreeNode*> s;
        while (!s.empty() || node)
        {
            if (node)
            {
                s.push(node);
                node = node->left;
            }
            else
            {
                node = s.top();
                res.push_back(node->val);
                s.pop();
                node = node->right;
            }
        }
        return res;
    }    
    
};
