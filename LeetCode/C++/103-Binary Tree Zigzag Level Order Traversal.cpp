// Thoughts: 
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        DFS(res, root, 1);
        for (int i = 1; i < res.size(); i += 2) {
            reverse(res[i].begin(), res[i].end());
        }
        return res;
    }
    
    void DFS(vector<vector<int>>& res, TreeNode* root, int level) {
        if (!root) return;
        if (res.size() < level) res.push_back(vector<int>());
        res[level - 1].push_back(root->val);
        DFS(res, root->left, level + 1);
        DFS(res, root->right, level + 1);
    }
};