class Solution {
public:
    /**
     * @param tokens The Reverse Polish Notation
     * @return the value
     */
    int evalRPN(vector<string>& tokens) {
        if (tokens.empty()) return 0;
        stack<string> stack;
        for (int i = 0; i < tokens.size(); i++) {
            //cout << "process: " << tokens[i] << " " << endl;
            if (isOperator(tokens[i])) {
                string input2 = stack.top();
                stack.pop();
                string input1 = stack.top();
                stack.pop();
                int val = calculate(input1, input2, tokens[i]);
                //cout << "val: " << val << endl;
                stack.push(to_string(val));
            } else {
                //cout << "push to stack: " << tokens[i] << endl;
                stack.push(tokens[i]);
            }
        }
        return stoi(stack.top());
    }
    
    bool isOperator(string op) {
        if (op.size() != 1) return false;
        char c = op[0];
        switch(c) {
            case '+':
            case '-':
            case '*':
            case '/':
            {
                return true;
                break;
            }
            default:
                return false;
        }
    }
    int calculate(string input1, string input2, string op) {
        int x = stoi(input1);
        int y = stoi(input2);
        if (op == "+") {
            return x + y;
        } else if (op == "-") {
            return x - y;
        } else if (op == "*") {
            return x * y;
        } else if (op == "/") {
            return x / y;
        } else {
            return 0;
        }
    }
};
