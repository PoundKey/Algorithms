// 1. classic combination and backtracking problem
// 2. runtime O(2^n)

class Solution {
public:
    /**
     * @param n: the given number
     * @return: Sum of elements in subsets
     */
    int subSum(int n) {
        if (n == 0) return 0;
        int res = 0;
        Traverse(res, 0, n, 1);
        return res;
    }
    
    void Traverse(int& res, int sum, int n, int pos)
    {
        res += sum;
        if (pos > n) return;
        
        for (int i = pos; i <= n; i++)
        {
            Traverse(res, sum + i, n, i + 1);
        }
    }
};
