// Thoughts: Stack, Stack, Stack.
// TODO: Dynamic Programming
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stack;
        int maxLen = 0, last = -1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stack.push(i);
            } else {
                if (stack.empty()) {
                    last = i;
                } else {
                    stack.pop();
                    if (stack.empty()) maxLen = max(maxLen, i - last);
                    else maxLen = max(maxLen, i - stack.top());
                }
            }
        }
        return maxLen;
    }
};
