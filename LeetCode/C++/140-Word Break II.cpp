class Solution {
private:
    unordered_map<string, vector<string>> d_memo;    
public:
    // memorization: top -> down
    // 1. check memo[T]
    // 2. calculate memo[T]
    // 3. set memo[T]
    // 4. return memo[T]
    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        if (s.empty() || wordDict.empty())
        {
            return {};
        }
        
        unordered_set<string> dict;
        for (const auto& str : wordDict)
        {
            dict.insert(str);
        }
        
        return wordBreak(s, dict);
    }
    
    vector<string> wordBreak(string s, unordered_set<string>& dict) 
    {
        if (d_memo.count(s))
        {
            return d_memo[s];
        }
        
        vector<string> result; // result here
        if (dict.count(s))
        {
            result.push_back(s);
        }
        
        for (int i = 1; i < s.size(); i++)
        {
            string strSuffix = s.substr(i);
            if (dict.count(strSuffix))
            {
                string strPrefix = s.substr(0, i);
                vector<string> subResult = wordBreak(strPrefix, dict);
                for (const auto& it : subResult)
                {
                    result.push_back(it + " " + strSuffix);
                }
            }
        }
        
        d_memo[s] = result;
        return result;
    }
    
    vector<string> wordBreakAlt(string s, vector<string>& wordDict) {
        vector<string> res;
        vector<string> curr;
        
        unordered_set<string> dict;
        for (const auto& str : wordDict)
        {
            dict.insert(str);
        }
        
        wordBreakBacktrack(res, curr, dict, s);
        return res;
    }
    
    void wordBreakBacktrack(vector<string>& res, vector<string>& curr, unordered_set<string>& dict, string s)
    {
        if (s.empty() && curr.size())
        {
            res.push_back(convertToString(curr));
            return;
        }
        
        for (int i = 1; i <= s.size(); i++)
        {
            string prefix = s.substr(0, i);
            if (dict.count(prefix))
            {
                curr.push_back(prefix);
                wordBreakBacktrack(res, curr, dict, s.substr(i));
                curr.pop_back();
            }
        }
    }
    
    string convertToString(const vector<string>& input)
    {
        string res;
        for (const auto& str : input)
        {
            res += str + " ";
        }
        res.pop_back();
        return res;
    }
};
