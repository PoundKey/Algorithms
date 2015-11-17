// Thoughts: Teo stacks implementations. Maintain a in and out stack.
class Queue {
private:
    stack<int> in, out;
public:
    // Push element x to the back of queue.
    void push(int x) {
        in.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        peek();
        out.pop();
    }

    // Get the front element.
    int peek(void) {
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
        return out.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return in.size() + out.size() == 0;
    }
};

//Thoughts: Single stack implementation. Push(x) takes O(n)
class Queue {
private:
    stack<int> st;
public:
    // Push element x to the back of queue.
    void push(int x) {
        stack<int> swap;
        while (!st.empty()) {
            swap.push(st.top());
            st.pop();
        }
        swap.push(x);
        while (!swap.empty()) {
            st.push(swap.top());
            swap.pop();
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        st.pop();
    }

    // Get the front element.
    int peek(void) {
        return st.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return st.empty();
    }
};