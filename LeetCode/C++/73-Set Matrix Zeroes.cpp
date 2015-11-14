// Thoughts: O(m+n) space. Notice we cannot directly set row and col to zeros 
// as we encounter M[i][j] = 0; that would result in a chain reaction.
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        int m = matrix.size(), n = matrix[0].size();
        vector<bool> row(m, false);
        vector<bool> col(n, false);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = true;
                    col[j] = true;
                }
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (row[i] || col[j])
                    matrix[i][j] = 0;
            }
        }
    }
};

// Thoughts: O(n) space complexity. //TODO
