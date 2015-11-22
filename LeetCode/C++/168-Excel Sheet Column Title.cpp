// Thoughts: 26 进制。
class Solution {
public:
    const string map = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string convertToTitle(int n) {
        string res;
        while (n) {
            int i = (n - 1) % 26;
            res += map[i];
            n = (n - 1) / 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};