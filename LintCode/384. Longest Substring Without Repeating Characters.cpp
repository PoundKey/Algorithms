class Solution {
public:
    /**
     * @param s: a string
     * @return: an integer 
     */
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        int n = s.size(), i = 0, j = i, res = 1;
        map<char, int> map;
        
        while (j < n) {
            if (map.count(s[j])) {
                res = max(res, j - i);
                i = max(map[s[j]] + 1, i);
            }
            map[s[j]] = j;
            j++;
        }
        res = max(res, j - i);
        return res;
    }

    int lengthOfLongestSubstringSquare(string s) {
        if (s.empty()) return 0;
        set<char> set;
        int n = s.size(), res;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (set.count(s[j])) break;
                set.insert(s[j]);
            }
            res = max(res, (int)set.size());
            set.clear();
        }
        return res;
    }
};
