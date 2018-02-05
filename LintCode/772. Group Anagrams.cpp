class Solution {
public:
    /**
     * @param strs: the given array of strings
     * @return: The anagrams which have been divided into groups
     */
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        vector<vector<string>> res;
        if (strs.empty()) return res;
        unordered_map<string, vector<string>> m;
        for (int i = 0; i < strs.size(); i++)
        {
            string key = strs[i];
            sort(key.begin(), key.end());
            m[key].push_back(strs[i]);
        }
        for (const auto& val : m)
        {
            res.push_back(val.second);
        }
        return res;
    }
};
