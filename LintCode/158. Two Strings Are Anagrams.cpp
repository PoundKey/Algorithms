// confirm if it's ANSI only
class Solution {
public:
    /**
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
    bool anagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int table[256] = {0};
        for (int i = 0; i < s.size(); i++) {
            table[s[i]]++;
        }
        for (int i = 0; i < t.size(); i++) {
            if (--table[t[i]] < 0) return false;
        }
        return true;
    }
};
