// 1. determine if number n is a prime number or not
// 2. initialize a prime number counter to 1
// 3. foreach number in [3, n], increase the counter if n is a prime number
// 4. return counter after finishing counting all the number in [3, n]

class Solution {
public:
    /**
     * @param n: the number
     * @return: the rank of the number
     */
    int kthPrime(int n) {
        int counter = 1;
        for (int i = 3; i <= n; i += 2)
        {
            if (isPrime(i)) counter++;
        }
        return counter;
    }
    
    bool isPrime(int val)
    {
        if (val <= 1) return false;
        if (val == 2) return true;
        if (val % 2 == 0) return false;
        int n = sqrt(val);
        for (int i = 3; i <= n; i += 2)
        {
            if (val % i == 0) return false;
        }
        return true;
    }
};
