class Solution {
public:
    /**
     * @param n: n
     * @param k: the k th permutation
     * @return: return the k-th permutation
     */
    string getPermutation(int n, int k) {
        vector<bool> visited(n + 1, false);
        string sol;
        Permutation(n, k, sol, visited);
        return sol;
    }
    
    void Permutation(int n, int& k, string& sol, vector<bool>& visited)
    {
        if (sol.size() == n) --k;
        if (k == 0) return;
        
        for (int i = 1; i <= n; i++)
        {
            if (visited[i]) continue;
            sol += to_string(i);
            visited[i] = true;
            Permutation(n, k, sol, visited);
            if (k == 0) break;
            sol.pop_back();
            visited[i] = false;
        }
    }
};
