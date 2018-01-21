// 1. xor to find all the different bits
// 2. n &= n - 1 to determine how many 1's
class Solution {
public:
    /**
     *@param a, b: Two integer
     *return: An integer
     */
    int bitSwapRequired(int a, int b) {
        // write your code here
        int count = 0, exec = a ^ b;
        while (exec != 0) {
            count++;
            exec &= exec - 1;
        }
        return count;
    }
};
