// Thoughts:    Same idea as Q54
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        if (n == 0) return res;
        int val = 1, row = 0, col = -1, hd = n, vd = n;
        while (true) {
            for (int i = 0; i < vd; i++){
                res[row][++col] = val++;
            }
            
            if (--hd == 0) break;
            for (int i = 0; i < hd; i++) {
                res[++row][col] = val++;
            }
            
            if (--vd == 0) break;
            for (int i = 0; i < vd; i++){
                res[row][--col] = val++;
            }
            
            if (--hd == 0) break;
            for (int i = 0; i < hd; i++) {
                res[--row][col] = val++;
            }
            if (--vd == 0) break;
        }
        return res;    
    }
};
