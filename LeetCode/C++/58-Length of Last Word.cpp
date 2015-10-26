// Thoughts: Notice the border condition: "a " => 1
// For couting problems, use variables to store the counting value
class Solution {
public:
    int lengthOfLastWord(string s) {
        int cur = 0, prev = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
               cur++; 
            } else {
                if (cur != 0) prev = cur;
                cur = 0;
            }
        }
        return cur == 0 ? prev : cur;
    }
};
