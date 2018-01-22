class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> A) {
        if (A.empty()) return -1;
        int start = 0, end = A.size() - 1;
        while (start <= end) {
            if (start == end) return end;
            int mid = start + (end - start) / 2;
            if (A[mid] > A[mid + 1])
                end = mid;
            else
                start = mid + 1;
        }
        return end;
        
    }
    int findPeakIter(vector<int> A) {
        if (A.empty()) return -1;
        int n = A.size();
        for (int i = 1; i < n - 1; i++) {
            if (A[i] > A[i-1] && A[i] > A[i+1]) return i;
        }
    }
};
