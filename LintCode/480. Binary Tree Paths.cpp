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
    
    /* key to BFS
       1. foreach node being visited, need additional filed or container to hold its previous path. e.g., pair<field, Node*>
       2. foreach iteration, BFS always deals with nodes that are in the same level
       3. update the field in pair<field, Node*> when push nodes to the queue.
    */
    void BFS(TreeNode* root)
    {
        if (root == NULL) return;
        vector<string> res;
        queue<pair<vector<int>, TreeNode*>> q;
        q.push(make_pair(vector<int>{}, root));
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                vector<int> vec = q.front().first;
                TreeNode* node = q.front().second;
                q.pop();
                if (node->left == NULL && node->right == NULL)
                {
                    vec.push_back(node->val);
                    res.push_back(genPath(vec));
                    continue;
                }
                vec.push_back(node->val);
                if (node->left)
                {
                    pair<vector<int>, TreeNode*> p(vec, node->left);
                    q.push(p);
                }
                if (node->right)
                {
                    pair<vector<int>, TreeNode*> p(vec, node->right);
                    q.push(p);                    
                }
            }

        }
    }
};
