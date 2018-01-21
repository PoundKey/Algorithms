class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        vector<string> res;
        if (strs.empty()) return res;
        map<string, int> map;
        for (auto& elem : strs) {
            string key = SortString(elem);
            map[key]++;
        }
        
        for (auto& elem : strs) {
            string key = SortString(elem);
            if (map[key] - 1 >= 1) res.push_back(elem);
        }
        return res;
    }
    
    string SortString(string s) {
        sort(s.begin(), s.end());
        return s;
    }

    vector<string> anagramsBruteforce(vector<string> &strs) {
        vector<string> res;
        if (strs.empty()) return res;
        for (int i = 0; i < strs.size(); i++) {
            for (int j = 0; j < strs.size(); j++) {
                if (i != j && isAnagram(strs[i], strs[j])) {
                    res.push_back(strs[i]);
                    break;
                }
            }
        }
        return res;
    }
    bool isAnagram(string& a, string& b) {
        if (a.size() != b.size()) return false;
        int A[256] = {0};
        for (int i = 0; i < a.size(); i++) {
            A[a[i]]++;
        }
        for (int j = 0; j < b.size(); j++) {
            if (--A[b[j]] < 0) return false;
        }
        return true;
    }
};
