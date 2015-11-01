// Thoughts: use a vector to as a dictionary to track all the [index : string] pair
// for each level i, compute options string s = dict[i].
// and the solution space is among [0...s.size()];

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> res;
        if (digits.size() == 0) return res;
        
        vector<string> dict;
        dict.push_back(" ");
        dict.push_back(" ");
        dict.push_back("abc");
        dict.push_back("def");
        dict.push_back("ghi");
        dict.push_back("jkl");
        dict.push_back("mno");
        dict.push_back("pqrs");
        dict.push_back("tuv");
        dict.push_back("wxyz");
        
        string curr;
        DFS(res, dict, digits, curr, 0);
        return res;
    }
    
    void DFS(vector<string>&res, vector<string>& dict, string& digits, string& curr, int level) {
        if (curr.size() == digits.size()) {
            res.push_back(curr);
            return;
        }
        
        int i = digits[level] - '0';  //compute the index 
        
        for (int j = 0; j < dict[i].size(); j++) {
            curr.push_back(dict[i][j]);
            DFS(res, dict, digits, curr, level+1);
            curr.pop_back();
        }
    }
};