class Solution {
public:
    /**
     * @param root the root of the binary tree
     * @return all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root == NULL) return res;
        vector<int> sol;
        traverse(root, res, sol);
        return res;
    }
    
    void traverse(TreeNode* root, vector<string>& res, vector<int>& sol) {
        if (root == NULL) return;
        sol.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            res.push_back(genPath(sol));
            sol.pop_back();
            return;
        }
        traverse(root->left, res, sol);
        traverse(root->right, res, sol);
        sol.pop_back();
    }
    
    string genPath(vector<int>& sol) {
        int n = sol.size();
        string res = "";
        for (int i = 0; i < n - 1; i++) {
            res += to_string(sol[i]) + "->";
        }
        res += to_string(sol[n-1]);
        return res;
    }
};
