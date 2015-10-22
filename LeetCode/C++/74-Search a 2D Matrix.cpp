// Thoughts: Starting from the bottom left, and use iteration.
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;
        int row = matrix.size() - 1;
        int len = matrix[0].size();
        int col = 0;
        while (row >=0 && col < len) {
            if (target < matrix[row][col])
                row--;
            else if (target > matrix[row][col])
                col++;
            else
                return true;
        }
        return false;
    }
};

// Thoughts: Starting from top right corner, same idea as above
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;
        int len = matrix.size();
        int row = 0;
        int col = matrix[0].size() - 1;
        while (row < len && col >=0) {
            if (target > matrix[row][col])
                row++;
            else if (target < matrix[row][col])
                col--;
            else
                return true;
        }
        return false;
    }
};

// Thoughts: Runtime: O(n). For each i from 0..n, if M[i][j] >= target, binarySearch(M[i])
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;
        int j = matrix[0].size() - 1;
        for (int i = 0; i < matrix.size(); i++) {
            if (target <= matrix[i][j]) 
                return binarySearch(matrix[i], target);
            else 
                continue;
        }
        return false;
    }
    
    bool binarySearch(vector<int> vec, int target) {
        int lo = 0;
        int hi = vec.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (target == vec[mid]) {
                return true;
            } else if (target > vec[mid]) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return false;
    }
};
