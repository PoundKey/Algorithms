/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector< vector<int> > res;
        vector<int> path;
        DFS(res, path, sum, root);
        return res;
    }
    
    void DFS(vector< vector<int> >& res, vector<int> path, int sum, TreeNode* root) {
        if (root == NULL) return;
        int val = root->val;
        path.push_back(val);
        if (val == sum && root->left == NULL && root->right == NULL) {
            res.push_back(path);
            return;
        }
        DFS(res, path, sum-val, root->left);
        DFS(res, path, sum-val, root->right);
    }
};