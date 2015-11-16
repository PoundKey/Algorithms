// Thoughts: Create a set and insert each sum of digits square. if dulplicate found, return false.
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> sum;
        while (n != 1) {
            int res = calc(n);
            if (res != 1 && sum.count(res)) return false;
            sum.insert(res);
            n = res;
        }
        return true;        
    }
    
    int calc(int n) {
        int result = 0, digit;
        while (n > 0) {
            digit = n % 10;
            result += digit * digit;
            n /= 10;
        }
        return result;
    }
};