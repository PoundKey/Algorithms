class Solution {
public:
    /**
     * @param n: non-negative integer n.
     * @return: return whether a binary representation of a non-negative integer n is a palindrome.
     */
    bool isPalindrome(int n) {
        string input;
        while (n)
        {
            input += to_string(n & 1);
            n = n >> 1;
        }
        return IsPalindrome(input);
    }
    
    bool IsPalindrome(string s)
    {
        if (s.size() <= 1) return true;
        int start = 0, end = s.size() - 1;
        while (start < end)
        {
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
};
