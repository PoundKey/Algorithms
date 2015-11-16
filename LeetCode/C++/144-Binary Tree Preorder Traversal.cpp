// Thoughts: Key is to use a stack as a container.
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> stack;
        stack.push(root);
        
        while (!stack.empty()) {
            TreeNode* top = stack.top();
            res.push_back(top->val);
            stack.pop();
            if (top->right) stack.push(top->right);
            if (top->left) stack.push(top->left);
        }
        return res;
    }
};

/**
 1) Create an empty stack nodeStack and push root node to stack.
 2) Do following while nodeStack is not empty.
    ….a) Pop an item from stack and print it.
    ….b) Push right child of popped item to stack
    ….c) Push left child of popped item to stack
    
*/