// Thoughts: Err, some rules we'll need to know from computer graphic class
// 1: Rotate by +90: Taking transpose, and reverse each row.
// 2: Rotate by -90: Taking transpose, and reverse each column.
// 3: Rotate by +180: Method 1. Reverse by +90 twice  Method 2: Reverse each row and reverse each column
// Stack Overflow Link: http://stackoverflow.com/questions/42519/how-do-you-rotate-a-two-dimensional-array
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        transpose(matrix);
        for (int i = 0; i < matrix.size(); i++) {
            reverse(matrix[i]);
        }
    }
    
    void transpose(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = i+1; j < matrix[0].size(); j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }
    
    void reverse(vector<int>& A) {
        int n = A.size();
        for (int i = 0; i < n/2; i++) {
            int temp = A[i];
            A[i] = A[n-1-i];
            A[n-1-i] = temp;
        }
    }
};