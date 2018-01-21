// 1. A[i-1] and A[i]
// 1.1 if A[i-1] == A[i], increase the counter
// 1.2 else, calculate the combination, and reset the counter to 1
class Solution {
public:
    /**
     * @param n the nth
     * @return the nth sequence
     */
    string countAndSay(int n) {
        if (n <= 0) return NULL;
        string prev = "1";
        while (n > 1) {
            string res;
            int count = 0, m = prev.size();
            for (int i = 0; i < m; i++) 
            {
                if (i == 0 || prev[i] == prev[i-1]) 
                {
                    count++;
                } 
                else 
                {
                    res += to_string(count) + prev[i-1];
                    count = 1;
                }
            }
            if (count >= 1) 
            {
                res += to_string(count) + prev[prev.size() - 1];
            }
            prev = res;
            n--;
        }
        return prev;
    }
};
