// Thoughts: Making sure that each key-value and value key pair is unique.
// use a map and a set to keep track of this.
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> map;
        unordered_set<string> set;
        int j = 0;
        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            string match = "";
            while (j < str.size() && str[j] != ' ') match += str[j++];
            if (match == "") return false;
            if (map.count(c) == 0) {
                if (set.count(match) != 0) return false;
                map[c] = match;
                set.insert(match);
            } else {
                if (map[c] != match) return false;
            }
            if (j < str.size()) j++;
        }
        return j == str.size();
    }
};