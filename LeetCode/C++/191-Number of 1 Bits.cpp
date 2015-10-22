// Thoughts: n-1 will turn right most 1-bit into 0 and the bit behind it into 1 bitss;
// Do n & n-1 will turn all the last 1-bit into 0-bit, and the bits behind it into 0 bits
// count++, count the 1 bit from right to left.
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n != 0) {
            n = n & n-1;
            count++;
        }
        return count;
    }
};
