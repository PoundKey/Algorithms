// 1. principle: x^n = x^(n/2) * x^(n/2)
// 2. binary search, recursion. When recovering the result
// 2.1 if n % 2 == 0, return val * val
// 2.2 if n % 2 == 1, return val * val * x
class Solution {
public:
    /**
     * @param x the base number
     * @param n the power number
     * @return the result
     */
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n > 0) return power(x, n);
        if (n < 0) return 1 / power(x, n);
    }
    
    double power(double x, int n) {
        if (n == 0) return 1;
        double val = power(x, n / 2);
        if (n % 2 == 0) return val * val;
        else return val * val * x;
    }
};
