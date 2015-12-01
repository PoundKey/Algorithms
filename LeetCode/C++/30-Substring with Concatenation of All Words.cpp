// Thoughts: Use two hashmap, one to record all the words, and the other to 
// record the words that have been included so far.
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (s.empty() || words.empty()) return res;
        int n = words.size(), m = words[0].size();
        unordered_map<string, int> t1;
        for (auto& str : words) t1[str]++;
        
        for (int i = 0; i <= ((int)s.size() - n * m); i++) {
            unordered_map<string, int> t2;
            int j = 0;
            while (j < n) {
                string str = s.substr(i + j * m, m);
                if (t1.count(str) == 0) break;
                t2[str]++;
                if (t2[str] > t1[str]) break;
                j++;
            }
            if (j == n) res.push_back(i);
        }
        return res;
    }
};