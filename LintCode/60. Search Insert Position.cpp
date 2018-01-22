class Solution {
    /** 
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
        // write your code here
        if (A.empty() || A.size() == 0) return 0;
        
        int start = 0;
        int end = A.size() - 1;
        while (start <= end) {
            int mid = start + (end - start)/2;
            if (A[mid] == target) {
                return mid;
            } else if (A[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }
};
