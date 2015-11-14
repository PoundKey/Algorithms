//Thoughts: Runtime O(n)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int val[26] = {0};
        for (int i = 0; i < s.size(); i++) val[s[i] - 'a']++;
        for (int i = 0; i < s.size(); i++) {
            if (--val[t[i] - 'a'] < 0) return false;
        }
        return true;
    }
};

//Thoughts: Runtime O(nlogn)
class Solution {
public:
    bool isAnagram(string s, string t) {
        //if (s.empty() || t.empty()) return false;
        if (s.size() != t.size()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t; 
    }
};