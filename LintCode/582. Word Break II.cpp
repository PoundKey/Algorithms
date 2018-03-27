class Solution {
public:
    /*
     * @param s: A string
     * @param wordDict: A set of words.
     * @return: All possible sentences.
     */
    vector<string> wordBreak(string &s, unordered_set<string> &wordDict) {
        vector<string> res;
        if (s.empty() || wordDict.empty()) return res;
        vector<string> sol; // single solution
        Traverse(res, sol, s, wordDict);
        return res;
    }
    
    void Traverse(vector<string>& res, vector<string>& sol, string s, unordered_set<string> &wordDict)
    {
        if (s.empty() && !sol.empty())
        {
            res.push_back(GenString(sol));
        }
        
        for (int i = 1; i <= s.size(); i++)
        {
            string subStr = s.substr(0, i);
            if (wordDict.count(subStr))
            {
                sol.push_back(subStr);
                Traverse(res, sol, s.substr(i), wordDict);
                sol.pop_back();
            }
        }
    }
    
    string GenString(const vector<string>& sol)
    {
        string res;
        if (sol.empty()) return res;
        for (const auto& str : sol)
        {
            if (!res.empty()) res += (" " + str);
            else res += str;
        }
        return res;
    }
};
