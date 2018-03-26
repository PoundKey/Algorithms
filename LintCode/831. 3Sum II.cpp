class Solution {
public:
    /**
     * @param n: an integer
     * @return: the number of solutions
     */
    int threeSum2(int n) {
        if (n == 0) return 1;
        int counter = 0;
        int val = sqrt(n);
        
        for (int i = 0; i <= val; i++)
        {
            int target = n - i * i;
            int start = i, end = val;
            
            while (start <= end)
            {
                int sum = start * start + end * end;
                if (sum == target)
                {
                    counter++;
                    start++;
                    end--;
                }
                else if (sum < target)
                {
                    start++;
                }
                else
                {
                    end--;
                }
            }
        }
        return counter;
    }
    
    // Combinations using backtracking
    int threeSum2(int n) {
        if (n == 0) return 1;
        int counter = 0;
        vector<int> sol;
        Traverse(sol, n, counter, 0);
        return counter;
    }
    
    void Traverse(vector<int>& sol, int n, int& counter, int pos)
    {
        if (sol.size() == 3)
        {
            if (Calculate(sol) == n) ++counter;
            return;
        }
        for (int i = pos; i <= sqrt(n); i++)
        {
            sol.push_back(i);
            Traverse(sol, n, counter, i);
            sol.pop_back();
        }
    }
    
    int Calculate(const vector<int>& sol)
    {
        if (sol.size() != 3) return 0;
        
        int res = 0;
        for (const auto& it : sol)
        {
            res += (it * it);
        }
        return res;
    }
};
