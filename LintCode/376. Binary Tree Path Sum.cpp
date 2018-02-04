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
    
    /* Solution using BFS *
    struct Path 
    {
        vector<int> path;
        TreeNode* node;
        int target;
        
        Path(const vector<int>& in_path, TreeNode* in_node, int in_target) :
        path(in_path), node(in_node), target(in_target)
        {
            
        }
    };
    
    vector<vector<int>> BFS(TreeNode *root, int target)
    {
        vector<vector<int>> res;
        if (root == NULL) return res;
        
        queue<Path> q;
        q.push(Path(vector<int>{}, root, target));
        
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                vector<int> path = q.front().path;
                TreeNode* node = q.front().node;
                int t = q.front().target;
                q.pop();
                if (node->left == NULL && node->right == NULL && node->val == t)
                {
                    path.push_back(node->val);
                    res.push_back(path);
                    continue;
                }
                path.push_back(node->val);
                t = t - node->val;
                if (node->left)
                {
                    q.push(Path(path, node->left, t));
                }
                if (node->right)
                {
                    q.push(Path(path, node->right, t));
                }
            }
        }
        return res;
    }
};
