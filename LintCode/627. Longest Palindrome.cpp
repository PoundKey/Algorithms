class Solution {
public:
    /*
     * @param s: a string which consists of lowercase or uppercase letters
     * @return: the length of the longest palindromes that can be built
     */
    int longestPalindrome(string s) {
        if (s.empty()) return 0;
        set<int> set; // keep track of character pair
        int res = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (set.count(s[i]))
            {
                set.erase(s[i]);
                res += 2;
            }
            else 
            {
                set.insert(s[i]);
            }
        }
        if (!set.empty()) res += 1;
        return res;
    }
};
