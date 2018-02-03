// 1. reverse both linkedlist so that we can add for the tail (right most digits)
// 2. foreach node pair (right most digits), sum = n1->val + n2->val + carry
// 3. create new node according to the sum, ListNode* node = new ListNode(sum)
// 4. create a new result linkedlist chain to hold the new node created from the sum
// 5. update the linkedlist, n1, n2, and carry
// 6. reverse the result linkedlist
class Solution {
public:
    /*
     * @param l1: The first list.
     * @param l2: The second list.
     * @return: the sum list of l1 and l2.
     */
    ListNode * addLists2(ListNode * l1, ListNode * l2) {
        if (l1 == NULL && l2 == NULL) return NULL;
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        ListNode* n1 = Reverse(l1);
        ListNode* n2 = Reverse(l2);
        ListNode dummy(0);
        ListNode* prev = &dummy;
        int carry = 0;
        while (n1 || n2 || carry)
        {
            // add the first node of n1 and the first node of n2
            if (n1)
            {
                carry += n1->val;
                n1 = n1->next; // update n1
            }
            if (n2)
            {
                carry += n2->val;
                n2 = n2->next; // update n2
            }
            int val = carry % 10;
            ListNode* node = new ListNode(val);
            prev->next = node;
            prev = node; // move the prev node to the current node
            carry /= 10;
        }
        return Reverse(dummy.next);
    }
    
    ListNode* Reverse(ListNode* node)
    {
        if (node == NULL || node->next == NULL) return node;
        // basic idea: foreach node, node->next = prevNode
        ListNode* prev = NULL;
        while (node != NULL)
        {
            ListNode* next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }
        return prev;
    }
};
