class Solution {
public:
    /*
     * @param a: The first integer
     * @param b: The second integer
     * @return: The sum of a and b
     */
    int aplusb(int x, int y) {
        // write your code here, try to do it without arithmetic operators.
        int carry = y;
        while (carry != 0) {
            int temp = x;
            x = x ^ carry;
            carry = (carry & temp) << 1;
        }
        return x;
    }
};
