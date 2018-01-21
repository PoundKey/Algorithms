// classic backtracking algorithm
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root the root of binary tree
     * @param target an integer
     * @return all valid paths
     */
    vector<vector<int>> binaryTreePathSum(TreeNode *root, int target) 
    {
        vector<vector<int>> res;
        vector<int> sol;
        traverse(root, res, sol, target);
        return res;
    }
    
    void traverse(TreeNode* root, vector<vector<int>>& res, vector<int>& sol, int target) 
    {
        if (root == NULL) return;
        int val = root->val;
        // check if it's the leaf node
        if (root->left == NULL && root->right == NULL && val == target)
        {
            sol.push_back(val);
            res.push_back(sol);
            sol.pop_back();
            return;
        }
        // keep searching if it's not a leaf node
        sol.push_back(val);
        traverse(root->left, res, sol, target - val);
        traverse(root->right, res, sol, target - val);
        sol.pop_back();
    }
};
