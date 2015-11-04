// Thoughts: Similar to Q2, reverse the string first, and reverse back in the end.
class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string res;
        int carry = 0;
        int n = max(a.size(), b.size());
        for (int i = 0; i < n; i++) {
            if (i < a.size()) carry += (a[i] - '0');
            if (i < b.size()) carry += (b[i] - '0');
            res += (carry%2 + '0');
            carry /= 2;
        }
        if (carry) res += '1';
        reverse(res.begin(), res.end());
        return res;
    }
};
