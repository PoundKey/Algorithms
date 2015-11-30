// Thoughts: O(mlog(n)) Runtime, m = rows, n = columns
// Can we do better...? Yeah.
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        for (int i = 0; i < matrix.size(); i++) {
            int start = 0, end = matrix[i].size() - 1;
            while (start <= end) {
                int mid = start + (end - start) / 2;
                if (matrix[i][mid] < target)
                    start = mid + 1;
                else if (matrix[i][mid] > target)
                    end = mid - 1;
                else
                    return true;
            }
        }
        return false;
    }
};

// Thoughts: O(m + n), just like the previous question. Q74
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        if (target < matrix[0][0] || target > matrix[m-1][n-1]) return false;
        int row = 0, col = n - 1;
        while (row < m && col >= 0) {
            if (matrix[row][col] > target)
                col--;
            else if (matrix[row][col] < target)
                row++;
            else
                return true;
        }
        return false;
    }
};