// Thoughts: Let's save some space and apply backtracking on a binary tree.
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        vector<int> cur;
        DFS(res, cur, root);
        return res;
    }
    
    void DFS(vector<string>& res, vector<int>& cur, TreeNode* root) {
        if (!root) return;
        if (!root->left && !root->right) {
            cur.push_back(root->val);
            res.push_back(genString(cur));
            cur.pop_back();
            return;
        }
        cur.push_back(root->val);
        DFS(res, cur, root->left);
        DFS(res, cur, root->right);
        cur.pop_back();
    }
    
    string genString(vector<int>& cur) {
        string res;
        int n = cur.size();
        for (int i = 0; i < n - 1; i++) {
            res += to_string(cur[i]);
            res += "->";
        }
        res += to_string(cur[n - 1]);
        return res;
    }
};
