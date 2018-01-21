class Solution {
public:
    /**
     * @param num a non-negative integer
     * @return one digit
     */
    int addDigits(int num) {
        int res = num;
        while (res > 9) {
            int val = 0;
            while (res != 0) {
                val += res % 10;
                res /= 10;
            }
            res = val;
        }
        return res;
    }
};
