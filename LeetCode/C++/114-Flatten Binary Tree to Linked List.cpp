// Thoughts: Recursive thoughts, return root if root has no children,
// return rightTail if it's avaible, or else the leftTail.
// Another way can also do it would be preorder traversal of the tree,
// push each element into a vector and then concatenate each element.
class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        flattenRec(root);
    }
    
    TreeNode* flattenRec(TreeNode* root) {
        if (!root) return NULL;
        TreeNode* leftTail = flattenRec(root->left);
        TreeNode* rightTail = flattenRec(root->right); 
        if (root->left) {
            TreeNode* temp = root->right;
            root->right = root->left;
            root->left = NULL;
            leftTail->right = temp;
        }
        if (rightTail) return rightTail;
        if (leftTail) return leftTail;
        return root;
    }
};
