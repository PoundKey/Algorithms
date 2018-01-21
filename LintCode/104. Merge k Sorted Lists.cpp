class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) return NULL;
        return mergeKListsHelper(lists, 0, lists.size() - 1);
    }
    
    ListNode *mergeKListsHelper(vector<ListNode *> &lists, int start, int end) {
        if (start > end) return NULL;
        if (start == end) return lists[start];
        if (start + 1 == end) return merge(lists[start], lists[end]);
        int mid = start + (end - start) / 2;
        ListNode* left = mergeKListsHelper(lists, start, mid);
        ListNode* right = mergeKListsHelper(lists, mid + 1, end);
        return merge(left, right);
    }
    
    ListNode* merge(ListNode* node1, ListNode* node2) {
        if (node1 == NULL && node2 == NULL) return NULL;
        ListNode dummy;
        ListNode* prev = &dummy;
        while (node1 || node2) {
            if (node1 && node2) {
                if (node1->val <= node2->val) {
                    prev->next = node1;
                    node1 = node1->next;
                } else {
                    prev->next = node2;
                    node2 = node2->next;
                }
            } else if (node1) {
                prev->next = node1;
                node1 = node1->next;
            } else {
                prev->next = node2;
                node2 = node2->next;
            }
            prev = prev->next;
        }
        return dummy.next;
    }
};
