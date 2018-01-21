class Solution {
public:
    /**
     * @param root: The root of the binary search tree.
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
    vector<int> res;
    vector<int> searchRange(TreeNode* root, int k1, int k2) {
        if (root == NULL) return res;
        search(root, k1, k2);
        return res;
    }
    void search(TreeNode* root, int k1, int k2) {
        if (root == NULL) return;
        if (root->val > k2) {
            searchRange(root->left, k1, k2);
        } else if (root->val < k1) {
            searchRange(root->right, k1, k2);
        } else {
            searchRange(root->left, k1, k2);
            res.push_back(root->val);
            searchRange(root->right, k1, k2);
        }        
    }
};
