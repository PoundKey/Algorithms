class Solution {
public:
    /**
     * @param s A string
     * @return Whether the string is a valid palindrome
     */
    bool isPalindrome(string& s) {
        if (s.empty()) return true;
        int start = 0, end = s.size() - 1;
        while (start < end) {
            while (!isalnum(s[start])) start++;
            while (!isalnum(s[end])) end--;
            if (start < end && tolower(s[start++]) != tolower(s[end--])) 
                return false;
        }
        return true;
    }
};
