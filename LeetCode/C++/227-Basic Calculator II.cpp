// Thoughts: use a stack to keep track of integers.
class Solution {
public:
    int calculate(string s) {
        stack<int> stack;
        int num = 0, n = s.size();
        char sign = '+';
        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                while (i < n && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
            }
            if (s[i] != ' ' || i == n - 1) {
                if (sign == '+') stack.push(num);
                if (sign == '-') stack.push(-num);
                if (sign == '*' || sign == '/') {
                    int temp = (sign == '*' ? stack.top() * num : stack.top() / num);
                    stack.pop();
                    stack.push(temp);
                }
                sign = s[i];
                num = 0;
            }
    
        }
        int res = 0;
        while (!stack.empty()) {
            res += stack.top();
            stack.pop();
        }
        return res;
    }
};