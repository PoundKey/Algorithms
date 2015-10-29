// Thoughts: 
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector< vector<int> > res;
        if (root == NULL) return res;
        DFS(res, root, 1);
    }
    
    void DFS(vector< vector<int> >& res, TreeNode* root, int level) {
        if (root == NULL) return;
        if (level > res.size()) {
            res.push_back(vector<int>());
        }
        res[level-1].push_back(root->val);
        DFS(res, root->left, level + 1);
        DFS(res, root->right, level + 1);
    }
};
