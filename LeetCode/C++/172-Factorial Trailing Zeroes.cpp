// Thoughts: http://www.purplemath.com/modules/factzero.htm
class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        long long x = 5;
        while (floor(n/x)) {
            res += floor(n/x);
            x *= 5;
        }
        return res;
    }
};
