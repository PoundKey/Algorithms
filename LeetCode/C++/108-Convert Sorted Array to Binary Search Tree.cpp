// Thoughts: Classic Divide and Conquer.
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return NULL;
        int start = 0, end = nums.size() - 1;
        return build(nums, start, end);
    }
    
    TreeNode* build(vector<int>& nums, int start, int end) {
        if (start > end) return NULL;
        int mid = start + (end - start) / 2;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = build(nums, start, mid - 1);
        node->right = build(nums, mid + 1, end);
        return node;
    }
};
