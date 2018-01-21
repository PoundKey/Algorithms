// 1. Need a variable to keep track of the max node, and remember to pass it to the paramter by reference
// 2. Traverse the entire tree recursively (in-order), update the maxNode constantly
// 3. Helper method needed
// 4. return maxNode
class Solution {
public:
    /**
     * @param root the root of binary tree
     * @return the max node
     */
    TreeNode* maxNode(TreeNode* root) {
        TreeNode* maxNode = root;
        maxNodeHelper(root, maxNode);
        return maxNode;
    }
    
    void maxNodeHelper(TreeNode* root, TreeNode*& maxNode) {
        if (root == NULL) return;
        if (root->val > maxNode->val) {
            maxNode = root;
        }
        maxNodeHelper(root->left, maxNode);
        maxNodeHelper(root->right, maxNode);
    }
    
};
