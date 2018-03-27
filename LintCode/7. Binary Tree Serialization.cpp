// I am gonna go with the level order traversal, pre-order traversal could also work

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
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode * root) {
        string res;
        if (root == NULL) return res;
        vector<string> sol;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            if (node == NULL)
            {
                sol.push_back("#");
            }
            else
            {
                sol.push_back(to_string(node->val));
                q.push(node->left);
                q.push(node->right);
            }
            
        }
        for (int i = 0; i < sol.size(); i++)
        {
            string del = res.empty() ? "" : ",";
            res += (del + sol[i]);
        }
        return res;
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TreeNode * deserialize(string &data) {
        if (data.empty()) return NULL;
        vector<string> A = Split(data);
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(A[0]));
        q.push(root);
        int i = 1;
        while (!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            if (node == NULL) continue;
            if (A[i] == "#")
            {
                node->left = NULL;
            }
            else
            {
                node->left = new TreeNode(stoi(A[i]));
                q.push(node->left);
            }
            i++;
            
            if (A[i] == "#")
            {
                node->right = NULL;
            }
            else
            {
                node->right = new TreeNode(stoi(A[i]));
                q.push(node->right);
            }
            i++;            
        }
        return root;
    }
    
    vector<string> Split(string data)
    {
        vector<string> res;
        if (data.empty()) return res;
        string DEL = ",";
        while (true)
        {
            int pos = data.find(DEL);
            if (pos == -1)
            {
                res.push_back(data);
                break;
            }
            else
            {
                res.push_back(data.substr(0, pos));
                data = data.substr(pos + 1);
            }
        }
        
        return res;
    }
};
