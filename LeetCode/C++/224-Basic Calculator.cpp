// Thoughts: Use stack to keep track of '+' and '-' sign for next operations.
class Solution {
public:
    int calculate(string s) {
        stack<int> stack;
        stack.push(1);
        stack.push(1);
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (isdigit(c)) {
                int num = 0;
                while (i < s.size() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                res += stack.top() * num;
                stack.pop();
                i--;
            } else if (c == '+' || c == '(') {
                stack.push(stack.top() * 1);
            } else if (c == '-') {
                stack.push(stack.top() * -1);
            } else if (c == ')') {
                stack.pop();
            }
        }
        return res;
    }
};