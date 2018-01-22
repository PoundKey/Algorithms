class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @return: Void
     */
    void rotate(vector<vector<int> > &matrix) {
        // To rotate +90 degree, first we calculate the
        // transpose of the matrix, then reverse each row
        if (matrix.empty()) return;
        transposeWithSpace(matrix);
        for (int i = 0; i < matrix.size(); i++) {
            reverse(matrix[i]);
        }
    }
    
    void transposeInPlace(vector<vector<int>>& matrix) {
        if (matrix.empty()) return;
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    
    void transposeWithSpace(vector<vector<int>>& matrix) {
        if (matrix.empty()) return;
        int n = matrix.size();
        vector<vector<int>> temp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                temp[j][i] = matrix[i][j];
            }
        }
        matrix = temp;
    }
    
    void reverse(vector<int>& row) {
        if (row.empty()) return;
        int n = row.size(), start = 0, end = n - 1;
        while (start <= end) {
            swap(row[start++], row[end--]);
        }
    }
    
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
};
