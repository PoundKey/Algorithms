// Thoughts: Hashtable to store the sorted string as the key.
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector< vector<string> > res;
        if (strs.empty()) return res;
        unordered_map<string, vector<string>> map;
        sort(strs.begin(), strs.end());
        for (int i = 0; i < strs.size(); i++) {
            string key = vsort(strs[i]);
            map[key].push_back(strs[i]);
        }
        
        for (auto& elem : map) {
            res.push_back(elem.second);
        }
        
    }
    
    string vsort(string s) {
        sort(s.begin(), s.end());
        return s;
    }
};