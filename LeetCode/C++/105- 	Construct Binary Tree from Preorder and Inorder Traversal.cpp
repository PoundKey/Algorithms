// Thoughts: Q105, just look out for the index offset. length always stays the same.
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size() - 1;
        return build(inorder, preorder, 0, n, 0, n);
    }
    
    TreeNode* build(vector<int>& io, vector<int>& po, int s1, int e1, int s2, int e2) {
        if (s1 > e1 || s2 > e2) return NULL;
        int val = po[s2];
        TreeNode* node = new TreeNode(val);
        int mid = find(io.begin(), io.end(), val) - io.begin();
        int len = mid - s1;
        node->left = build(io, po, s1, mid - 1, s2 + 1, s2 + len);
        node->right = build(io, po, mid + 1, e1, s2 + len + 1, e2);
        return node;
    }

};
