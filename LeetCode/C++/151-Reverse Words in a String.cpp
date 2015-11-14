// Thoughts: Let i be the index of first character of a word, 
// and let j be the index of the first space " " after the word.
class Solution {
public:
    void reverseWords(string &s) {
        string res;
        int j = s.size();
        int i = j - 1;
        while (i >= 0) {
            if (s[i] == ' ') {
                j = i;
            } else if (i == 0 || s[i-1] == ' ') {
                if (!res.empty()) res += ' ';
                res += s.substr(i, j - i);
            }
            i--;
        }
        s = res;
    }
};