class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if (0 == n)
        {
            return res;
        }
        
        backtrack(res, "", n, 0, 0);
        return res;
    }
    
    /**
        本质：pre-order DFS
    **/
    void backtrack(vector<string>& res, string curr, int n, int left, int right)
    {
        if (curr.size() == 2 * n)
        {
            res.push_back(curr);
            return;
        }
        
        if (left < n)
        {
            backtrack(res, curr + "(", n, left + 1, right);
        }
        
        if (right < left)
        {
            backtrack(res, curr + ")", n, left, right + 1);    
        }
    }
};
