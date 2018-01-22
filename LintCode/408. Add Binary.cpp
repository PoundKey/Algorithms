class Solution {
public:
    string addBinary(string& a, string& b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        int i = 0, j = 0;
        int n = a.size(), m = b.size();
        
        string res;
        int carry = 0;
        
        while (i < n || j < m) {
            
            if (i < n) {
                carry = carry + (a[i] - '0');
                i++;
            }
            
            if (j < m) {
                carry = carry + (b[j] - '0');
                j++;
            }
            
            res.push_back((carry % 2) + '0');
            carry = carry >= 2 ? 1 : 0;
        }
        
        if (carry) res.push_back('1');
        reverse(res.begin(), res.end());
        return res;
    }
};
