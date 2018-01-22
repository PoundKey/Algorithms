class Solution {
    /** 
     * param A : an integer ratated sorted array
     * param target :  an integer to be searched
     * return : an integer
     */
public:
    int search(vector<int> &A, int target) {
        if (A.empty()) return -1;
        return searchInRange(A, target, 0, A.size() - 1);
    }
    
    int searchInRange(vector<int> &A, int target, int start, int end) {
        if (start > end) return -1;
        int mid = start + (end - start) / 2;
        if (A[mid] == target) {
            return mid;
        }
        if (A[mid] > A[start]) {
            // sorted A[start, mid]
            if (A[mid] > target && A[start] <= target) {
                searchInRange(A, target, start, mid - 1);
            } 
            else {
                searchInRange(A, target, mid + 1, end);
            }
        } else {
            // unsorted A[start, mid], sorted A[mid, end]
            if (A[mid] < target && A[end] >= target) {
                searchInRange(A, target, mid + 1, end);
            } 
            else {
                searchInRange(A, target, start, mid - 1);
            }
        }
    }
};
