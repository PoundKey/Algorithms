// Thoughts: Let use inorder traversal and O(n) space first
class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> list;
        vector<int> vals;
        traverse(list, vals, root);
        sort(vals.begin(), vals.end());
        for (int i = 0; i < list.size(); i++)
            list[i]->val = vals[i];
    }
    
    void traverse(vector<TreeNode*>& list, vector<int>& vals, TreeNode* root) {
        if (!root) return;
        traverse(list, vals, root->left);
        list.push_back(root);
        vals.push_back(root->val);
        traverse(list, vals, root->right);
    }
};
