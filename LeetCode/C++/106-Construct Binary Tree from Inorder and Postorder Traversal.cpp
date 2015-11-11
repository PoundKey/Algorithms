// Thoughts: Extract the root by val = postorder[end], and extract val's index in inorder
// notice that we will have to do this recursively, meaning each time we need to re-allocate
// the starting index and ending index from both in-order and post-order vectors.
// This can be achieve by measuring the length and calcualting the offset.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size() - 1;
        return build(inorder, postorder, 0, n, 0, n);
    }
    
    TreeNode* build(vector<int>& io, vector<int>& po, int s1, int e1, int s2, int e2) {
        if (s1 > e1 || s2 > e2) return NULL;
        int val = po[e2];
        TreeNode* node = new TreeNode(val);
        int mid = find(io.begin(), io.end(), val) - io.begin();
        int len = mid - s1;
        node->left = build(io, po, s1, mid - 1, s2, s2 + len - 1);
        node->right = build(io, po, mid + 1, e1, s2 + len, e2 - 1);
        return node;
    }
};
