// Thoughts: Brute force O(nm)
class Solution {
public:
    int strStr(string haystack, string needle) {
        int hlen = haystack.size();
        int nlen = needle.size();
        if (!nlen || !hlen && !nlen) return 0;
        if (hlen < nlen) return -1;
        for (int i = 0; i <= hlen - nlen; i++) {
            int p = i;
            for (int j = 0; j < nlen; j++) {
                if (haystack[p] != needle[j]) break;
                if (j == nlen - 1) return i;
                p++;
            }
        }
        return -1;
    }
};

// Thoughts: Clean code provided by leetcode
class Solution {
public:
    int strStr(string haystack, string needle) {
        int hlen = haystack.size();
        int nlen = needle.size();
        for (int i = 0; ; i++) {
            for (int j = 0; ; j++) {
                if (j == nlen) return i;
                if (i + j == hlen) return -1;
                if (needle[j] != haystack[i + j]) break;
            }
        }
    }
};