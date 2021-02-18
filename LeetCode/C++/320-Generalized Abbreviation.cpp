class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        if (word.empty())
        {
            return {};
        }
        vector<string> res;
        backtrack(res, "", word, 0, 0);
        return res;
    }
    
    void backtrack(vector<string>& res, string curr, string word, int start, int count)
    {
        if (start == word.size())
        {
            if (count)
            {
                curr += to_string(count);
            }
            res.push_back(curr);
            return;
        }
        
        // two choices here: 
        // 1. keep the character 
        // 2. abbreviate it
        backtrack(res, curr, word, start + 1, count + 1);
        curr = curr + (count ? to_string(count) : "") + word[start];
        backtrack(res, curr, word, start + 1, 0);
    }
};
