class Solution {
public:
    /** 
     *@param A: A list of integers
     *@param elem: An integer
     *@return: The new length after remove
     */
    int removeElement(vector<int> &A, int elem) {
        if (A.empty()) return 0;
        int n = A.size(), i = 0, j = 0;
        while (j < n) {
            if (A[j] == elem) {
                j++;
            } else {
                swap(A[i++], A[j++]);
            }
        }
        return i;
    }

    int removeElementAlt(vector<int> &A, int elem) {
        if (A.empty()) return 0;
        int n = A.size(), i = 0, j = n - 1;
        while (i <= j) {
            if (A[i] == elem) {
                A[i] = A[j--];
            } else {
                i++;
            }
        }
        return i;
    }
    
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }
};
