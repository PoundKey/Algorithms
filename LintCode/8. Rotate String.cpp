// 1. rotate first part
// 2. rotate second part
// 3. rotate the entire part
class Solution {
public:
    /**
     * @param str: a string
     * @param offset: an integer
     * @return: nothing
     */
    void rotateString(string &str,int offset){
        string res;
        if (str.empty()) return;
        int n = str.size() - offset % str.size();
        for (int i = n; i < str.size(); i++) {
            res += str[i];
        }
        for (int i = 0; i < n; i++) {
           res += str[i];
        }
        str = res;
    }
};
