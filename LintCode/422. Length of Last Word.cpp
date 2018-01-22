class Solution {
public:
    /**
     * @param s A string
     * @return the length of last word
     */
    int lengthOfLastWord(string& s) {
        int prev = 0, curr = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                if (curr != 0) prev = curr;
                curr = 0;
            } 
            else {
                curr += 1;
            }
        }
        return curr == 0 ? prev : curr;
    }
};
