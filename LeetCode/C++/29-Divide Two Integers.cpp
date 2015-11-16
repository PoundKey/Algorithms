// Thoughts: Let's use multiplication anyways, results in a timeout. log(n) runtime
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        int sign = (dividend >= 0 && divisor > 0) || (dividend < 0 && divisor < 0) ? 1 : -1;
        int a = abs(dividend), b = abs(divisor);
        int start = 1, end = a;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (b * mid == a) {
                return mid;
            } else if (b * mid < a) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return end * sign;
    }
};
