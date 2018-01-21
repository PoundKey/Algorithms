class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        // write your code here
        if (!source || !target) return -1;
        int hlen = strlen(source), nlen = strlen(target);
        if (nlen == 0) return 0;
        if (hlen == 0) return -1;
        for (int i = 0; i <= hlen - nlen; i++) {
            for (int j = 0; j <= nlen; j++) {
                if (j == nlen) return i;
                if (source[i+j] != target[j]) break;
            }
        }
        return -1;
    }
};
