// Thinking: Traverse the vector from size()-1 to 0
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1, sum;
        for (int i = digits.size()-1; i >=0; i--) {
            sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum/10;
        }
        if (carry) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

// Thinking: Trace to the end of the vector, and return 1 if vector[last] + 1 >= 10
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int result = trace(digits, 0);
        if (result == 1) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
    
    int trace(vector<int>& digits, int index) {
        if (index == digits.size()-1) {
            return addUp(digits, index);
        }
        int result = trace(digits, index+1);
        if (result == 1) {
            return addUp(digits, index);
        } 
        return 0;
    }
    
    int addUp(vector<int>& digits, int index) {
            int res = digits[index] += 1;
            digits[index] = res % 10;
            return (res >= 10) ? 1 : 0;
    }
};

// Thinking: Covert back to integer and plus one, then convert the integer back to a vector
// Did not solve the INT overflow problem
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int sum = 0;
        for (int i=0; i<digits.size(); i++) {
            sum = sum*10 + digits[i];
        }
        sum += 1;
        vector<int> result;
        generateVec(sum, result);
        return result;
    }
    
    void generateVec(int num, vector<int> &vec) {
        if (num < 10) {
            vec.push_back(num);
            return;
        }
        generateVec(num/10, vec);
        vec.push_back(num % 10);
    }
};