// Thoughts: Reverse the entire string, and reverse back each word one by one. 
class Solution {
public:
    void reverseWords(string &s) {
        reverse(s, 0, s.size() - 1);
        int i = 0, j = 0;
        while (j < s.size()) {
            if (j == s.size() - 1 || s[j] == ' ') {
                reverse(s, i, j - 1);
                i = j + 1;
            }
            j++;
        }
    }
    
    void reverse(string& s, int start, int end) {
        int n = start + end + 1;
        for (int i = start; i < n / 2; i++) {
            char temp = s[i];
            s[i] = s[n-1-i];
            s[n-1-i] = temp;
        }
    }
};

