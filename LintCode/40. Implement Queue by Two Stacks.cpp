// 1. s1 = push stack, s2 = pop stack
// 2. if s2 is empty, shift all the items in s1 to s2, in this way we get first in first out order
// 3. if s2 is not empty, pop the element in s2

class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }

    /*
     * @param element: An integer
     * @return: nothing
     */
    void push(int element) {
        s1.push(element);
    }

    void shiftStack()
    {
        if (!s2.empty()) return;
        while (!s1.empty())
        {
            int el = s1.top();
            s1.pop();
            s2.push(el);
        }
    }
    /*
     * @return: An integer
     */
    int pop() {
        shiftStack();
        int el = s2.top();
        s2.pop();
        return el;
    }

    /*
     * @return: An integer
     */
    int top() {
        shiftStack();
        int el = s2.top();
        return el;    
    }
};
