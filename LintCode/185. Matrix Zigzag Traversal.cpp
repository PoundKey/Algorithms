class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @return: a vector of integers
     */
    vector<int> printZMatrix(vector<vector<int> > &matrix) {
        vector<int> res;
        if (matrix.empty() || matrix[0].empty()) return res;
        traverse(matrix, res, true, 0, 0);
        return res;
    }
    
    void traverse(vector<vector<int> > &matrix, vector<int>& sol, bool goingUp, int i, int j) {
        int m = matrix.size(), n = matrix[0].size();
        if (i == m || j == n) return; //base case
        if (i >= 0 && i < m && j >= 0 && j < n) {
            sol.push_back(matrix[i][j]);
        }
        if (goingUp) {
            if (i - 1 >= 0 && j + 1 < n) {
                traverse(matrix, sol, true, i - 1, j + 1);
            } else if (i - 1 < 0 && j + 1 < n) {
                // deal with condition 1
                traverse(matrix, sol, false, i, j + 1);
            } else {
                // deal with condition 2, j + 1 == n
                traverse(matrix, sol, false, i + 1, j);
            }
        } else {
            if (j - 1 >= 0 && i + 1 < m) {
                traverse(matrix, sol, false, i + 1, j - 1);
            } else if (j - 1 < 0 && i + 1 < m) {
                traverse(matrix, sol, true, i + 1, j);
            } else {
                // deal with situation 2, i + 1 == m
                traverse(matrix, sol, true, i, j + 1);
            }
        }
    }
};
