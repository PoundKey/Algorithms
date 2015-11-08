// Thoughts: Dynamic Programming
// 1. Every ugly number can generate three different ugly numbers: i * 2, i * 3, i * 5;
// 2. We know the first ugly number, which is 1. therefore we know 2, 3, 5, the candidates from second ugly number.
// 3. compute the the second ugly number by min(l1, l2, l5)
// 4. Increase the counter.
class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 0) return n;
        vector<int> res(n + 1, 0);
        res[1] = 1;
        int l1 = 1, l2 = 1, l3 = 1;
        for (int i = 2; i <= n; i++) {
            int v1 = res[l1] * 2, v2 = res[l2] * 3, v3 = res[l3] * 5;
            int val = min(v1, min(v2, v3));
            res[i] = val;
            if (v1 == val) l1++;
            if (v2 == val) l2++;
            if (v3 == val) l3++;
        }
        return res[n];
    }
    
};
