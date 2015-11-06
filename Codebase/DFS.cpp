#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Find the node got traversed the last with DFS
TreeNode* findTail(TreeNode* root) {
	if (root == NULL) return NULL;
	TreeNode* leftTail = findTail(root->left);
	TreeNode* rightTail = findTail(root->right);
	
	if (rightTail) return rightTail;
	if (leftTail) return leftTail;
	return root; // leave node
}