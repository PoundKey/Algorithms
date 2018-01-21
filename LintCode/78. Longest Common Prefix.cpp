class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty()) return "";
        string s = strs[0], res;
        int n = s.size(), i = 0;
        while (i < n) {
            char match = s[i];
            for (int j = 1; j < strs.size(); j++) {
                string s2 = strs[j];
                if (i >= s2.size() || s2[i] != match) return res;
            }
            res += match;
            i++;
        }
        return res;
    }
};
