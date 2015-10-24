// Thoughts: Notice the top left and the bottom left situation, 
// where next = 0 and next = increasement
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        string res;
        int inc = (numRows - 1) * 2;
        for (int i=0; i < numRows; i++) {
            int j = i, next = (numRows - i - 1) * 2;
            while (j < s.size()) {
                res.push_back(s[j]);
                if (next > 0 && next < inc && (j + next) < s.size()) {
                    res.push_back(s[j+next]);
                }
                j += inc;
            }
        }
        return res;
    }
};
