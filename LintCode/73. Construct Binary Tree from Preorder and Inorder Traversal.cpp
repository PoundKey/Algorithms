// 1. we know for pre-order traversal, the first item is the root.
// 2. second item in the vector is the direct left child node, key is to find the position of the direct right child node.
// 3. use the in-order vector, find the size of the left subtree for the given root node, record as len.
// 4. in the pre-order vector, advance (len) from the index of the direct left child node, we get the index of the direct right child node.
// 5. recursively create the left and right child nodes.

class Solution {
    /**
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.empty() || inorder.empty()) return NULL;
        int n = preorder.size();
        return BuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
    }
    
    TreeNode* BuildTree(vector<int> &preOrder, vector<int> &inOrder, int preStart, int preEnd, int inStart, int inEnd)
    {
        if (preStart > preEnd || inStart > inEnd) return NULL;
        int val = preOrder[preStart];
        TreeNode* node = new TreeNode(val);
        int mid = find(inOrder.begin(), inOrder.end(), val) - inOrder.begin();
        int len = mid - inStart;
        
        node->left = BuildTree(preOrder, inOrder, preStart + 1, preStart + len, inStart, mid - 1);
        node->right = BuildTree(preOrder, inOrder, preStart + len + 1, preEnd, mid + 1, inEnd);
        return node;
    }
};
