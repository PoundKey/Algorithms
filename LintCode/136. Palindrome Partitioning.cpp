class Solution {
public:
    /*
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string>> partition(string &s) {
        vector<vector<string>> res;
        if (s.empty()) return res;
        vector<string> sol;
        Traverse(res, sol, s);
    }
    
    void Traverse(vector<vector<string>>& res, vector<string>& sol, string s)
    {
        if (s.empty())
        {
            res.push_back(sol);
            return;
        }
        for (int i = 1; i <= s.size(); i++)
        {
            string substr = s.substr(0, i);
            if (IsPalindrome(substr))
            {
                sol.push_back(substr);
                Traverse(res, sol, s.substr(i));
                sol.pop_back();
            }
        }
    }
    
    bool IsPalindrome(const string& s)
    {
        if (s.size() <= 1) return true;
        int start = 0, end = s.size() - 1;
        while (start < end)
        {
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
};
