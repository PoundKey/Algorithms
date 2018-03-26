class Solution {
public:
    /**
     * @param s: a string
     * @return: it's index
     */
    int firstUniqChar(string &s) {
        if (s.empty()) return -1;
        // the character and index pair, invalidate the index of character is not unique
        map<char, int> map; 
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            map.count(c) > 0 ? map[c] = -1: map[c] = i;
        }
        
        int minIndex = INT_MAX;
        for (const auto& it : map)
        {
            if (it.second != -1)
            {
                minIndex = min(minIndex, it.second);
            }
        }
        return minIndex == INT_MAX ? -1 : minIndex;
    }
};
