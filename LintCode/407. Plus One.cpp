class Solution {
public:
    /**
     * @param digits a number represented as an array of digits
     * @return the result
     */
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        vector<int> res;
        int carry = 1;
        for (int i = 0; i < digits.size(); i++) {
            int val = carry + digits[i];
            res.push_back(val % 10);
            carry = val / 10;
        }
        if (carry >= 1) res.push_back(1);
        reverse(res.begin(), res.end());
        return res;
    }
};
