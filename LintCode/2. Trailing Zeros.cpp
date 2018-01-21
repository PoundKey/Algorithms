class Solution {
 public:
    // param n : description of n
    // return: description of return 
    long long trailingZeros(long long n) {
        long long res = 0;
        while (n != 0) {
            res += n / 5;
            n /= 5;
        }
        return res;
    }
};
