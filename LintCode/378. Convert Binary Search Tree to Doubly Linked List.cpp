/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 * Definition of Doubly-ListNode
 * class DoublyListNode {
 * public:
 *     int val;
 *     DoublyListNode *next, *prev;
 *     DoublyListNode(int val) {
 *         this->val = val;
           this->prev = this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of tree
     * @return: the head of doubly list node
     */
    DoublyListNode* bstToDoublyList(TreeNode* root) {
        if (root == NULL) return NULL;
        DoublyListNode dummy(0);
        DoublyListNode* prev = &dummy;
        DFS(prev, root);
        return dummy.next;
    }
    
    // create linklist recursively, in-order
    void DFS(DoublyListNode*& prev, TreeNode* root) {
        if (root == NULL) return;
        DFS(prev, root->left);
        DoublyListNode* node = new DoublyListNode(root->val);
        prev->next = node;
        node->prev = prev;
        prev = node;
        DFS(prev, root->right);
    }
};

