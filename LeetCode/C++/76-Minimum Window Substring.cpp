// Thoughts: 
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";
        if (s == t) return s;
        unordered_map<char, int> map;
        int start = 0, end = 0, count = 0, n = s.size();
        string res = "";
        for (auto& c : t) map[c] += 1;
        
        while (end < n) {
            char c = s[end];
            if (t.find(c) != -1) {
                map[c]--;
                if (map[c] >= 0) count++;
            }
            if (count == t.size()) {
                if (res == "") res = s.substr(start, end - start + 1);
                c = s[start];
                while (t.find(c) == -1 || map[c] < 0) {
                    if (t.find(c) != -1) map[c]++;
                    start++;
                    c = s[start];
                    int len = end - start + 1;
                    if (res.size() > len) res = s.substr(start, len);
                }              
            }
            end++;
        }
        return res;
    }
};

// Thoughts: Use an ASCII array to replace the hashmap, for better performance.
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";
        if (s == t) return s;
        int map[256] = {0};
        int start = 0, end = 0, count = 0, n = s.size();
        string res = "";
        for (auto& c : t) map[c] += 1;
        
        while (end < n) {
            char c = s[end];
            if (t.find(c) != -1) {
                map[c]--;
                if (map[c] >= 0) count++;
            }
            if (count == t.size()) {
                if (res == "") res = s.substr(start, end - start + 1);
                c = s[start];
                while (t.find(c) == -1 || map[c] < 0) {
                    if (t.find(c) != -1) map[c]++;
                    start++;
                    c = s[start];
                    int len = end - start + 1;
                    if (res.size() > len) res = s.substr(start, len);
                }              
            }
            end++;
        }
        return res;
    }
};