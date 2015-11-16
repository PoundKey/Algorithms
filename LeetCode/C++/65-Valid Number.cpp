// Thoughts: keep track of boolean isNumeric as the on/off switch to simplify calculation.
class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();
        if (n == 0) return true;
        int i = 0;
        bool isNumeric = false;
        
        while (i < n && s[i] == ' ') i++;
        if (i < n && (s[i] == '+' || s[i] == '-')) i++;
        while (i < n && isdigit(s[i])) {
            i++;
            isNumeric = true;
        }
        if (i < n && s[i] == '.') {
            i++;
            while(i < n && isdigit(s[i])) {
                i++;
                isNumeric = true;
            }
        }
        if (i < n && isNumeric && s[i] == 'e') {
            i++;
            isNumeric = false;
            if (i < n && (s[i] == '+' || s[i] == '-')) i++;
            while(i < n && isdigit(s[i])) {
                i++;
                isNumeric = true;
            }
        }
        while (i < n && s[i] == ' ') i++;
        return isNumeric && i == n;
    }
};