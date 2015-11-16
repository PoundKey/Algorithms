// Thoughts: Modifiy the order preorder traversal to: node, right, and left.
// reverse the result from this traversal gives us: left, right and node, which is the post-order traversal.
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;
        TreeNode* node = root;
        stack<TreeNode*> stack;
        stack.push(node);
        while (!stack.empty()) {
           node = stack.top();
           stack.pop();
           res.push_back(node->val);
           if (node->left) stack.push(node->left);
           if (node->right) stack.push(node->right);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};


//Ref: http://liangjiabin.com/blog/2015/10/binary-tree-traversal.html
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;
        TreeNode* curr = root, *prev = root;
        stack<TreeNode*> stack;
        stack.push(root);
        
        while (!stack.empty()) {
            curr = stack.top();
            
            if (curr->left == prev || curr->right == prev || !curr->left && !curr->right) {
                res.push_back(curr->val);
                stack.pop();
                prev = curr;
            } else {
                if (curr->right) stack.push(curr->right);
                if (curr->left) stack.push(curr->left);
            }
        }
        return res;
    }
};