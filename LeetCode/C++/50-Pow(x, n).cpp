// Thoughts: x^n = x^(n/2) * x^(n/2) * x^(n%2)
class Solution {
public:
    double myPow(double x, int n) {
        double res = divide(x, abs(n));
        return n >= 0 ? res : 1/res;
    }
    
    double divide(double x, int n) {
        if (n == 0) return 1;
        double res = divide(x, n/2);
        res *= res;
        if (n % 2) res *= x;
        return res;
    }
};

// Thoughts: Bit Manipulation
class Solution {
public:
    double myPow(double x, int n) {
        int j = abs(n);
        double res = 1;
        for (int i = 31; i >= 0; i--) {
            res *= res;
            if (j & (1 << i)) res *= x;
        }
        return n >=0 ? res : 1/res;
    }
    
};