// Thoughts: Nothing much, just brute force. Runtime: O(nm)
// when the array contain contains one string, return that string.
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        if (strs.empty()) return prefix;
        string first = strs[0];
        for (int i = 0; i < first.size(); i++) {
            for (int j = 0; j < strs.size(); j++) {
                if (first[i] != strs[j][i]) return prefix;
                if (j == strs.size()-1) prefix += first[i];
            }
        }
        return prefix;
    }
};