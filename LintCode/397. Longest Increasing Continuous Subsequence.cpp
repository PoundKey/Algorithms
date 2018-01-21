class Solution {
public:
    /**
     * @param A an array of Integer
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int>& A) {
        if (A.empty()) return 0;
        int res = 1, curInc = 1, curDec = 1;
        for (int i = 1; i < A.size(); i++) {
            if (A[i] == A[i-1]) {
                curInc = 1;
                curDec = 1;
            } else if (A[i] > A[i-1]) {
                curInc += 1;
                curDec = 1;
            } else {
                // the array is descending at i
                curDec += 1;
                curInc = 1;
            }
            res = max(res, max(curInc, curDec));
        }
        return res;
    }
};
