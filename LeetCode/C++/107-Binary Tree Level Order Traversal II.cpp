// Thoughts: Just need to reverse the elements after finished.
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        DFS(res, root, 1);
        int n = res.size();
        for (int i = 0; i < n / 2; i++) {
            vector<int> temp = res[i];
            res[i] = res[n-1-i];
            res[n-1-i] = temp;
        }
        return res;
    }
    void DFS(vector<vector<int>>& res, TreeNode* root, int level) {
        if (!root) return;
        if (res.size() < level) res.push_back(vector<int>());
        res[level-1].push_back(root->val);
        DFS(res, root->left, level + 1);
        DFS(res, root->right, level + 1);
    }
};
