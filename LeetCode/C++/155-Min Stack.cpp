// Thoughts: 
class MinStack {
private:
    stack<int> elem;
    stack<int> minStack;
public:
    void push(int x) {
        elem.push(x);
        if (minStack.empty() || x <= minStack.top()) minStack.push(x);
    }

    void pop() {
        if (!elem.empty()) {
            if (elem.top() == minStack.top()) minStack.pop();
            elem.pop();
        } 
    }

    int top() {
        return elem.top();
    }

    int getMin() {
        return minStack.top();
    }
};
