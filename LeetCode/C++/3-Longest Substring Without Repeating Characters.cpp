// Thoughts:  V1, using a hashmap to track existing characters and their position.
// mark down the last appearance of the same character. 
// last varible + 1 indicates the start index of "GOOD" part. (inclusive)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> dict;
        int maxLen = 0, curLen = 0, last = 0;
        for (int i = 0; i < s.size(); i++) {
            if (!dict.count(s[i])) {
                dict[s[i]] = i;
                curLen++;
            } else {
                if (dict[s[i]] > last) last = dict[s[i]];
                curLen = i - last;
                dict[s[i]] = i;
            }
            maxLen = max(maxLen, curLen);
        }
        return maxLen;
    }
};

// Thoughts: //TODO: Revisit when starting dynamic programming
// here it comes, the dynamic programming way!
// dp[i]: the length of the longest non-repeated string between [0:i-1], with length i.
// STE: dp[i] = min(i - A[i], dp[i-1] + 1);
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int map[256];
        memset(map, -1, 256*sizeof(int));
        int maxLen = 0, curLen = 0;
        for (int i = 1; i <= s.size(); i++) {
            int index = s[i-1];
            if (map[index] == -1) {
                curLen++;
            } else {
                curLen = min(curLen + 1, i - map[index]);
            }
            map[index] = i;
            maxLen = max(maxLen, curLen);
        }
        return maxLen;
    }
};