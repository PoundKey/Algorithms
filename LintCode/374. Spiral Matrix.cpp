class Solution {
public:
    /**
     * @param matrix a matrix of m x n elements
     * @return an integer array
     */
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty() || matrix[0].empty()) return res; // base case
        int m = matrix.size(), n = matrix[0].size();
        int row = 0, col = -1;
        
        while (true) {
            for (int i = 0; i < n; i++) {
                res.push_back(matrix[row][++col]);
            }
            if (--m == 0) break; // reduce row
            
            for (int j = 0; j < m; j++) {
                res.push_back(matrix[++row][col]);
            }
            if (--n == 0) break; // reduce column
            
            for (int i = 0; i < n; i++) {
                res.push_back(matrix[row][--col]);
            }
            if (--m == 0) break;
            
            for (int j = 0; j < m; j++) {
                res.push_back(matrix[--row][col]);
            }
            if (--n == 0) break;
        }
        return res;
    }
};
