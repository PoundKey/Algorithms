class Solution {
public:
    /**
     * @param s A string
     * @return whether the string is a valid parentheses
     */
    bool isValidParentheses(string& s) {
        if (s.empty()) return true;
        stack<char> stack;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stack.push(s[i]);
            } else {
                if (s[i] == ')') {
                    if (stack.top() != '(') return false;
                    stack.pop();
                }
                if (s[i] == '}') {
                    if (stack.top() != '{') return false;
                    stack.pop();
                }
                if (s[i] == ']') {
                    if (stack.top() != '[') return false;
                    stack.pop();
                }
            }
        }
        return stack.empty();
    }
};
