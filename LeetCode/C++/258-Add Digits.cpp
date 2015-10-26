// Thoughts:  with iteration/recursion
class Solution {
public:
    int addDigits(int num) {
        int result = num;
        while(result > 9) {
            result = sum(result);
        }
        return result;
    }
    
    int sum(int num) {
        int result = 0;
        while(num > 0) {
            result += (num % 10);
            num /= 10;
        }
        return result;
    }
};

// Thoughts: without iteration, solution O(1) implies a formula.
// Observe that: output = (input - 1) % 9 + 1
class Solution {
public:
    int addDigits(int num) {
        return (num - 1) % 9 + 1;
    }
};


