class Solution {
public:
    /**
     * @param str: a string
     * @return: a boolean
     */
    bool isUnique(string &str) {
        set<char> set;
        for (int i = 0; i < str.size(); i++) {
            if (set.count(str[i])) return false;
            set.insert(str[i]);
        }
        return true;
    }
};
