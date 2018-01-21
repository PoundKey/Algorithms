class MinStack {
public:
    MinStack() {
        // do initialization if necessary
    }

    void push(int number) {
        m_stack.push(number);
        
        if (m_minStack.empty() || number <= m_minStack.top()) {
            m_minStack.push(number);
        }
    }

    int pop() {
        int top = m_stack.top();
        if (!m_minStack.empty() && top == m_minStack.top()) {
            m_minStack.pop();
        }
        m_stack.pop();
        return top;
    }

    int min() {
        return m_minStack.top();
    }
private:  
    stack<int> m_stack;
    stack<int> m_minStack;
};
