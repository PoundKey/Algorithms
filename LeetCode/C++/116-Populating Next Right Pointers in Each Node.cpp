// Thoughts: 
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        DFS(root, NULL);
    }
    
    void DFS(TreeLinkNode* root, TreeLinkNode* target) {
        if (root == NULL) return;
        root->next = target;
        DFS(root->left, root->right);
        if (root->next) {
            DFS(root->right, root->next->left);
        } else {
            DFS(root->right, NULL);
        }
    }
};
