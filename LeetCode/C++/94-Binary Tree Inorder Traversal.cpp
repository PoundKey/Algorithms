// Thoughts: Traverse all the way to the left until node = null.
// start poping node out from the stack, and set node = node->right when finishing.
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;
        TreeNode* node = root;
        stack<TreeNode*> stack;
        while (node || !stack.empty()) {
            while (node) {
                stack.push(node);
                node = node->left;
            }
            node = stack.top();
            stack.pop();
            res.push_back(node->val);
            node = node->right;
        }
        return res;
    }
};
