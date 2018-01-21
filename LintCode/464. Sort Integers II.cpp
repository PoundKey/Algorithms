// Practice mergesort

class Solution {
public:
    /**
     * @param A an integer array
     * @return void
     */
    void sortIntegers2(vector<int>& A) {
        if (A.empty() || A.size() == 1) return;
        mergeSort(A, 0, A.size() - 1);
    }
    
    void mergeSort(vector<int>& A, int start, int end) {
        if (start >= end) return;
        int mid = start + (end - start) / 2;
        mergeSort(A, start, mid);
        mergeSort(A, mid + 1, end);
        merge(A, start, mid, end);
    }
    
    void merge(vector<int>& A, int start, int mid, int end) {
        if (A.empty()) return;
        vector<int> res;
        int i = start, j = mid + 1;
        while (i <= mid || j <= end) {
            if (i <= mid && (j > end || A[i] <= A[j])) {
                res.push_back(A[i++]);
            } else {
                res.push_back(A[j++]);
            }
        }
        for (int i = start; i <= end; i++) {
            A[i] = res[i-start];
        }
    }
};
