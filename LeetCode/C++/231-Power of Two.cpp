// Thoughts: when a number is power of 2, it contains a single 1-bit in binary form
// Notice: for input <= 0, return false
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 1) return false;
        int count = 0;
        while (n != 0) {
            n &= n-1;
            count++;
        }
        return (count == 1) ? true : false;
    }
};