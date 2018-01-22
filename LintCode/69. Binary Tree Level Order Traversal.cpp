class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: Level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (root == NULL) return res;
        queue<TreeNode*> queue;
        queue.push(root);
        TreeNode* node;
        while (!queue.empty()) {
            int n = queue.size();
            vector<int> level;
            for (int i = 0; i < n; i++) {
                node = queue.front();
                queue.pop();
                level.push_back(node->val);
                if (node->left) queue.push(node->left);
                if (node->right) queue.push(node->right);
            }
            res.push_back(level);
        }
        return res;
    }

    vector<vector<int>> levelOrderDFS(TreeNode *root) {
        vector<vector<int>> res;
        if (root == NULL) return res;
        traverse(root, res, 0);
        return res;
    }    
    
    void traverse(TreeNode* root, vector<vector<int>>& res, int level) {
        if (root == NULL) return;
        if (res.size() < level + 1) res.resize(level + 1);
        res[level].push_back(root->val);
        traverse(root->left, res, level + 1);
        traverse(root->right, res, level + 1);
    }
};
