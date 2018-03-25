// 1. we know for post-order traversal, the last item in the post-order vector is the root.
// 2. second last item in the post order vector is the direct right child node, 
//    key is to be able to identify the ranges of the left and right subtrees in the post-order vector.
// 3. use the in-order vector, find the size of the left subtree for the given root node, record as len.
// 4. at this point, we are able to identify the range of both left and right subtrees in the post-order vector:
//    left tree range -> [start, start + len - 1], right tree range -> [start + len, end - 1]
// 5. recursively create the left and right child nodes based on the subtrees' range.

class Solution {
public:
    /**
     * @param inorder: A list of integers that inorder traversal of a tree
     * @param postorder: A list of integers that postorder traversal of a tree
     * @return: Root of a tree
     */
    TreeNode * buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (postorder.empty() || inorder.empty()) return NULL;
        int n = postorder.size();
        return BuildTree(inorder, postorder, 0, n - 1, 0, n - 1);
    }
    
    TreeNode* BuildTree(vector<int>& inOrder, vector<int>& postOrder, int inStart, int inEnd, int postStart, int postEnd)
    {
        if (inStart > inEnd || postStart > postEnd) return NULL;
        int val = postOrder[postEnd];
        TreeNode* node = new TreeNode(val);
        
        int mid = find(inOrder.begin(), inOrder.end(), val) - inOrder.begin();
        int len = mid - inStart;
        
        node->left = BuildTree(inOrder, postOrder, inStart, mid - 1, postStart, postStart + len - 1);
        node->right = BuildTree(inOrder, postOrder, mid + 1, inEnd, postStart + len, postEnd - 1);
        return node;
    }
};
