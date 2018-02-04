// 1. use BFS to traverse the entire tree, save the result into a 2D vector
// 2. foreach odd item (1D vector) in the result vector, reverse the 1D vector
// 2.1 alternatively, we could use a alternating boolean to decide whether we 
//     should insert to the front or the back of the 1D vector foreach level in BFS

class Solution {
public:

    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (root == NULL) return res;
        queue<TreeNode*> queue;
        TreeNode* node;
        queue.push(root);
        while (!queue.empty()) {
            int n = queue.size();
            vector<int> level;
            for (int i = 0; i < n; i++) {
                node = queue.front();
                queue.pop();
                level.push_back(node->val);
                if (node->left) queue.push(node->left);
                if (node->right) queue.push(node->right);
            }
            res.push_back(level);
        }
        for (int i = 1; i < res.size(); i += 2) {
            reverse(res[i].begin(), res[i].end());
        }
        return res;
    }
    
    vector<vector<int>> zigzagLevelOrderAlt(TreeNode *root) {
        vector<vector<int>> res;
        if (root == NULL) return res;
        queue<TreeNode*> queue;
        TreeNode* node;
        queue.push(root);
        bool alter = false;
        while (!queue.empty()) {
            int n = queue.size();
            vector<int> level;
            for (int i = 0; i < n; i++) {
                node = queue.front();
                queue.pop();
                if (alter) {
                    level.insert(level.begin(), node->val);
                } else {
                    level.push_back(node->val);
                }
                if (node->left) queue.push(node->left);
                if (node->right) queue.push(node->right);
            }
            res.push_back(level);
            alter = !alter;
        }
        return res;
    }
    
};
