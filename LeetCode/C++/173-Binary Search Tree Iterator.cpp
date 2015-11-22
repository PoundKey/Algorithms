// Thoughts: Did a in-order tree traversal to push all the nodes into a queue.
class BSTIterator {
private:
    queue<TreeNode*> Q;
public:
    BSTIterator(TreeNode *root) {
        //In-order traversal of BST
        stack<TreeNode*> S;
        TreeNode* node = root;
        while (node || !S.empty()) {
            while (node) {
                S.push(node);
                node = node->left;
            }
            node = S.top();
            S.pop();
            Q.push(node);
            node = node->right;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !Q.empty();
    }

    /** @return the next smallest number */
    int next() {
        if (!hasNext()) return INT_MIN;
        int res = Q.front()->val;
        Q.pop();
        return res;        
    }
};

// Thoughts: Another more efficient implementation with stack being used.
class BSTIterator {
private:
    stack<TreeNode*> S;
    TreeNode* curr;
public:
    BSTIterator(TreeNode *root) {
        curr = root;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (curr || !S.empty());
    }

    /** @return the next smallest number */
    int next() {
        while (curr) {
            S.push(curr);
            curr = curr->left;
        }
        curr = S.top();
        S.pop();
        int res = curr->val;
        curr = curr->right;
        return res;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */