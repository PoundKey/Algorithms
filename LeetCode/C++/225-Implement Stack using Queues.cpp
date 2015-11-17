// Thoughts: 1. pop(): pop and push elements from the queue except the last one. use var = queue.size() - 1 to track index
// 2. top(): pop and push elements all over again from the queue, use var = queue.front() to keep track of the last element got pushed.
class Stack {
private:
    queue<int> q;
public:
    // Push element x onto stack.
    void push(int x) {
        q.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        int loop = q.size();
        while (loop > 1) {
            q.push(q.front());
            q.pop();
            loop--;
        }
        q.pop();
    }

    // Get the top element.
    int top() {
        int loop = q.size(), front;
        while (loop) {
            front = q.front();
            q.pop();
            q.push(front);
            loop--;
        }
        return front;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
};