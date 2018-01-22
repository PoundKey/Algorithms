class Solution {
public:
    /**
     * @param n an integer
     * @return true if this is a happy number or false
     */
    bool isHappy(int n) {
        set<int> table;
        while (n != 1) {
            int sum = 0;
            while (n != 0) {
                int digit = n % 10;
                sum += digit * digit;
                n /= 10;
            }
            if (table.count(sum) == 0) {
                table.insert(sum);
            } else {
                return false;
            }
            n = sum;
        }
        return true;
    }
};
