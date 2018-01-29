class BSTIterator {
private:
    stack<TreeNode*> container;
public:
    /*
    * @param root: The root of binary tree.
    */BSTIterator(TreeNode * root)
    {
        pushToStack(root);
    }
    
    /* recursively push current node and it's left node to stack */
    void pushToStack(TreeNode* node)
    {
        while (node)
        {
            container.push(node);
            node = node->left;
        }
    }
    /*
     * @return: True if there has next node, or false
     */
    bool hasNext() {
        return container.size() > 0;
    }

    /*
     * @return: return next node
     */
    TreeNode * next() {
        if (container.empty()) return NULL;
        TreeNode* top = container.top();
        container.pop();
        pushToStack(top->right);
        return top;
    }
};
