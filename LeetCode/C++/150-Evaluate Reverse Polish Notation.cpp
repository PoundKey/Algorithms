// Thoughts: Just stack operations.
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        for (int i = 0; i < tokens.size(); i++) {
            if (!isOp(tokens[i])) {
                stack.push(stoi(tokens[i]));
            } else {
                int y = stack.top();
                stack.pop();
                int x = stack.top();
                stack.pop();
                int val = eval(x, y, tokens[i][0]);
                stack.push(val);
            }
        }
        return stack.top();
    }
    
    bool isOp(string s) {
        if (s == "+" || s == "-" || s == "*" || s=="/") return true;
        return false;
    }
    
    int eval(int x, int y, char symbol) {
        switch (symbol) {
            case '+' : return x + y;
            case '-' : return x - y;
            case '*' : return x * y;
            case '/' : return x / y;
            default : return INT_MAX;
        }
    }
};