class Solution {
public:
    /** 
     * @param chars: The letters array you should sort.
     */
    void sortLetters(string &letters) {
        if (letters.empty()) return;
        int start = 0, end = 0, n = letters.size();
        // between [start,end-1], valid candidates are zoned
        while (end < n) {
            if (letters[end] < 'a') {
                end++;
            } else {
                swap(letters[end++], letters[start++]);
            }
        }
    }
    
    void swap(char& a, char& b) {
        char temp = a;
        a = b;
        b = temp;
    }
    
    void sortLettersNLOGN(string &letters) {
        sort(letters.begin(), letters.end());
        reverse(letters.begin(), letters.end());
    }
};
