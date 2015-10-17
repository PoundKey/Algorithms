class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0) return false;
        stack<char> iStack; //init stack
        iStack.push(s[0]);
        for (int i=1; i<s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                iStack.push(s[i]);
            } else {
                if ( (s[i] == ')' && iStack.top() != '(') 
                    ||(s[i] == '}' && iStack.top() != '{') 
                    ||(s[i] == ']' && iStack.top() != '[') ) {
                    return false;
                } else {
                    iStack.pop();
                }
            }
        }  
        return iStack.empty();
    }
	};