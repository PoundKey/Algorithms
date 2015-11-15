// Thoughts: for x, sqrt(x) must be between 0 to x, let do binary search.
// Be aware of overflow.
class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x;
        int lo = 0, hi = x;  
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (x / mid == mid) {
                return mid;
            } else if (x / mid < mid) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return hi;
    }
};

// Some rules: When we use binary search to find x in a sorted array A, if x cannot
// be found within the array, then the loop terminates with lo > hi, therefore,
// A[hi] < x < A[lo], given hi >= 0 and lo < A.size().