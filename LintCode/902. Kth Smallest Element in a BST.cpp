// 1. looks like that we are implemention an inorder binary tree iterator
// 2. if (node != NULL) traverse all the way to the left, else pop from the stack if !stack.empty()
// 3. use a stack to store the node along the path when traverse to the left
// 4. when a node got pop out of the stack, it's the candidate node, --k

class Solution {
public:
    /**
     * @param root: the given BST
     * @param k: the given k
     * @return: the kth smallest element in BST
     */
    int kthSmallest(TreeNode * root, int k) {
        if (root == NULL) return -1;
        stack<TreeNode*> stack;
        TreeNode* node = root;
        while (!stack.empty() || node)
        {
            if (node)
            {
                stack.push(node);
                node = node->left;
            }
            else 
            {
                node = stack.top();
                stack.pop();
                if (--k == 0) return node->val;
                node = node->right;
            }
        }
        return INT_MIN;
    }
};
