// Thoughts: 
// Thoughts: Bit Manipulation
// 1: n & 1 outputs the value for the right-most digits, either 1 or 0;
// 2: n >> i shift n by i bits, equivalent to n / 2^i
// 3: res = res | ((n >> i) & 1) << (31 - i);
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; i++) {
           res |= ((n >> i) & 1) << (31 - i);
        }
        return res;
    }
};

// easier to read version.
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; ++i) {
            res = res << 1;
            res |= n & 1;
            n = n >> 1;
        }
        return res;
    }
};
