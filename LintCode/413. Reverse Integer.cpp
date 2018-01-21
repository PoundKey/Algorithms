class Solution {
public:
    /**
     * @param n the integer to be reversed
     * @return the reversed integer
     */
    int reverseInteger(int n) {
        bool negative = n < 0 ? true : false;
        n = abs(n);
        int res = 0;
        while (n != 0) {
            if (res > INT_MAX / 10) return 0;
            res = res * 10 + n % 10;
            n /= 10;
        }
        if (negative) res *= -1;
        return res;
    }
};
