// Thoughts: 
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        DFS(res, root, 1);
        return res;
    }
    void DFS(vector<int>& res, TreeNode* root, int level) {
        if (root == NULL) return;
        if (res.size() < level) {
            res.push_back(root->val);
        } else {
            res[level-1] = root->val;
        }
        DFS(res, root->left, level + 1);
        DFS(res, root->right, level + 1);
    }
};