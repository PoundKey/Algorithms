// Thoughts: 
// 1. Circulations between four directions, start with A[0][-1]
// 2. when either horizontal direction or vertical direction reaches 0, break and return
// 3. decrease m after each horizontal tracing, and --n after each vertical tracing
// 4. length of tracing? Always m or n, which are responsive after step 3.
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty()) return res;
        int m = matrix.size(), n = matrix[0].size();
        int row = 0, col = -1;
        while (true) {
            for (int i = 0; i < n; i++) {
                res.push_back(matrix[row][++col]);
            }
            
            if (--m == 0) break;
            for (int i = 0; i < m; i++) {
                res.push_back(matrix[++row][col]);
            }
            
            if (--n == 0) break;
            for (int i = 0; i < n; i++) {
                res.push_back(matrix[row][--col]);
            }
            
            if (--m == 0) break;
            for (int i = 0; i < m; i++) {
                res.push_back(matrix[--row][col]);
            }
            
            if (-- n == 0) break;
        }
        return res;
    }
};
