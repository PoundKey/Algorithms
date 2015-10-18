class Solution {
public:
    bool isPalindrome(int x) {
        int result = reverse(x);
        return (result == 10) ? false : (result == x);
    }
    
    int reverse(int x) {
       int result = 0;
       while (x > 0) {
				 if (abs(result) > INT_MAX/10) return 10; //let 10 be the identifer when the input overflows
           result = result*10 + x%10;
           x = x/10;
       }
       return result;
    }
};