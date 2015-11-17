// Thoughts: If the heightLeft == heightRight, it's a full binary tree, return 2^h - 1
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        int heightLeft = 0, heightRight = 0;
        TreeNode* r1 = root, *r2 = root;
        while (r1) {
            heightLeft++;
            r1 = r1->left;
        } 
        while (r2) {
            heightRight++;
            r2 = r2->right;
        }
        if (heightLeft == heightRight) return pow(2, heightLeft) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};