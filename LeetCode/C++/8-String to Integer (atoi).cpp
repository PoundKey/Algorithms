// Thoughts: Skip 
class Solution {
public:
    int myAtoi(string str) {
        if (str.empty()) return 0;
        int n = str.size(), i = 0, sign = 1;
        while (i < n && (str[i] == ' ')) i++;
        if (isalpha(str[i])) return 0;
        if (i < n && !isdigit(str[i])) {
            if (str[i] == '-') sign = -1;
            i++;
        }
        
        int res = 0;
        while (i < n && isdigit(str[i])) {
            int digit = str[i] - '0';
            if (res > INT_MAX/10 || res == INT_MAX/10 && digit > 7) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            res = res*10 + digit;
            i++;
        }
        return res * sign;
    }
};