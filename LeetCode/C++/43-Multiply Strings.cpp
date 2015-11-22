// Thoughts: Just follow the regular procedures of multiplication rule. Some thing worth noticing:
// 1: m x n, the maxiumum length that the result can get is len(m) + len(n)
// 2: The position in the vector shifts as i and j increases, res[i+j] is the correct pos.
// 2: Remove the redundant leading '0's once the result is computed.
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.empty() || num2.empty()) return "";
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int m = num1.size(), n = num2.size();
        string res(m + n, '0');
        for (int i = 0; i < n; i++) {
            int carry = 0;
            int val = num2[i] - '0';
            for (int j = 0; j < m; j++) {
                carry += val * (num1[j] - '0') + (res[i+j] - '0');
                res[i+j] = carry % 10 + '0';
                carry /= 10;
            }
            if (carry) res[i + m] = carry + '0';
        }
        reverse(res.begin(), res.end());
        while (res.size() > 1 && res[0] == '0') res.erase(0, 1);
        return res;
    }
};