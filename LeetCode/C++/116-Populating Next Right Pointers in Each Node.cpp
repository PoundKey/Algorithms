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
    
    void DFS(TreeLinkNode* root, TreeLinkNode* next) {
        if (root == NULL) return;
        root->next = next;
        DFS(root->left, root->right);
        if (next) {
            DFS(root->right, next->left);
        } else {
            DFS(root->right, NULL);
        }
    }
};
