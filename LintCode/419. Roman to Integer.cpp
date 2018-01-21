class Solution {
public:
    /**
     * @param s Roman representation
     * @return an integer
     */
    int romanToInt(string& s) {
        if (s.empty()) return 0;
        int n = s.size(), res = 0;
        map<char, int> map{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        for (int i = 0; i < n; i++) {
            if (i + 1 == n) res += map[s[i]];
            else {
                int add = map[s[i]] < map[s[i+1]] ? -map[s[i]] : map[s[i]];
                res += add;
            }
        }
        return res;
    }
};
