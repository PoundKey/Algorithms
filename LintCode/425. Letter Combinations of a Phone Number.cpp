class Solution {
public:
    /**
     * @param digits A digital string
     * @return all posible letter combinations
     */
    map<int, string> m = {
        {2, "abc"},
        {3, "def"},
        {4, "ghi"},
        {5, "jkl"},
        {6, "mno"},
        {7, "pqrs"},
        {8, "tuv"},
        {9, "wxyz"}
    };
    vector<string> letterCombinations(string& digits) {
        // Write your code here
        vector<string> res;
        string sol = "";
        if (digits.empty()) return res;
        DFS(res, sol, digits, 0);
        return res;
    }
    
    void DFS(vector<string>& res, string& sol, string& digits, int pos) {
        if (sol.size() == digits.size()) {
            res.push_back(sol);
            return;
        }
        string str = m[(digits[pos] - '0')];
        for (int i = 0; i < str.size(); i++) {
            sol += str[i];
            DFS(res, sol, digits, pos + 1);
            sol.pop_back();
        }
    }
};
