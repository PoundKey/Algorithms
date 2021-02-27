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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> res;
        
        if (!root || !target)
        {
            return res;
        }
        
        if (K == 0)
        {
            res.push_back(target->val);
            return res;
        }
        
        unordered_map<TreeNode*, TreeNode*> dict; // child : parent
        DFS(dict, root, NULL);
        unordered_set<TreeNode*> visited;
        
        queue<TreeNode*> queue;
        queue.push(target);
        visited.insert(target);
        
        // 每一次循环都是一次平行时空
        while (K > 0 && queue.size()) // 循环
        {
            int n = queue.size(); // 平行时空
            for (int i = 0; i < n; i++)
            {
                TreeNode* node = queue.front();
                queue.pop();
                
                TreeNode* leftChild = node->left;
                if (leftChild && !visited.count(leftChild))
                {
                    queue.push(leftChild);
                    visited.insert(leftChild);
                }
                
                TreeNode* rightChild = node->right;
                if (rightChild && !visited.count(rightChild))
                {
                    queue.push(rightChild);
                    visited.insert(rightChild);
                }
                
                if (dict.count(node) && !visited.count(dict[node]))
                {
                    TreeNode* parent = dict[node];
                    if (parent)
                    {
                        queue.push(parent);
                        visited.insert(parent);
                    }
                }
            }
            K--;
        }
        
        while (queue.size())
        {
            TreeNode* node = queue.front();
            queue.pop();
            res.push_back(node->val);
        }
        
        return res;
    }
    
    void DFS(unordered_map<TreeNode*, TreeNode*>& dict, TreeNode* node, TreeNode* parent)
    {
        if (!node)
        {
            return;
        }
    
        dict[node] = parent;
        DFS(dict, node->left, node);
        DFS(dict, node->right, node);
    }
};
