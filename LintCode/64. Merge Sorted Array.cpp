class Solution {
public:
    void mergeSortedArray(int A[], int m, int B[], int n) {
        int i = 0, j = 0;
        int temp[m+n];
        while (i < m || j < n) {
            if (i < m && (j == n || A[i] <= B[j])) {
                temp[i+j] = A[i++];
            } else {
                temp[i+j] = B[j++];
            }
        }
        for (int i = 0; i < m + n; i++) {
            A[i] = temp[i];
        }
    }
};
