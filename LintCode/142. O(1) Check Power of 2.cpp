class Solution {
public:
    /*
     * @param n: An integer
     * @return: True or false
     */
    bool checkPowerOf2(int n) {
        if (n <= 0) return false;
        n = n & (n - 1);
        return n == 0;
    }
};
