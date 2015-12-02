// Thoughts: Source: http://simpleandstupid.com/2014/10/26/wildcard-matching-leetcode-%E8%A7%A3%E9%A2%98%E7%AC%94%E8%AE%B0/
class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0, n = s.size(), m = p.size();
        int star = -1, mark = -1;
        while (i < n) {
            if (j < m && (s[i] == p[j] || p[j] == '?')) {
                i++;
                j++;
            } else if (j < m && p[j] == '*') {
                star = j;
                j++;
                mark = i;
            } else if (star != -1) {
                j = star + 1;
                mark++;
                i = mark;
            } else {
                return false;
            }
        }
        while (j < m && p[j] == '*') j++;
        return j == m;
    }
};