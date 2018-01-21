class Solution {
public:
    /**
     * @param s : A string
     * @return : A string
     */
    string reverseWords(string s) {
        if (s.empty()) return s;
        string res;
        string temp;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ' ') {
                if (!temp.empty()) {
                    string space = res.empty() ? "" : " ";
                    res = res + space + temp;
                    temp.clear();
                }
            } 
            else {
                temp = s[i] + temp;
            }
        }
        if (!temp.empty()) {
            string space = res.empty() ? "" : " ";
            res = res + space + temp;
        }
        return res;
    }
    
    string reverseWordsOpt(string s) {
        if (s.empty()) return s;
        string res;
        int len = s.size(), i = len - 1, j = i;
        while (i >= 0) {
            if (s[i] == ' ') {
                j = i;
            } 
            else {
                if (i < len-1 && s[i+1] == ' ') j = i;
                if (i == 0 || s[i-1] == ' ') {
                    if (!res.empty()) res += " ";
                    res += s.substr(i, j-i+1);
                }
            }
            i--;
        }
        return res;
    }
};
