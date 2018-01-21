class Solution {
public:
    /**
     * @param A an integer array sorted in ascending order
     * @param target an integer
     * @return an integer
     */
    int findPosition(vector<int>& A, int target) {
        if (A.empty()) return -1;
        int n = A.size();
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (target <= A[mid])
                high = mid - 1;
            else 
                low = mid + 1;
        }
        if (low < n-1 && A[low] == target) return low;
        return -1;
    }

    int findPositionHigh(vector<int>& A, int target) {
        if (A.empty()) return -1;
        int n = A.size();
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (target >= A[mid])
                low = mid + 1;
            else 
                high = mid - 1;
        }
        if (high > 0 && A[high] == target) return high;
        return -1;
    }
    
    int findPositionA(vector<int>& A, int target) {
        if (A.empty()) return -1;
        int n = A.size();
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (A[mid] == target)
                return mid;
            else if (target > A[mid])
                low = mid + 1;
            else 
                high = mid - 1;
        }
        return -1;
    }
};
