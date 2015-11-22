// Thoughts: Same concept applied from Q51. Remember to set: colForRow[row] = i
class Solution {
public:
    int totalNQueens(int n) {
        vector<int> colForRow(n);
        int res = 0;
        DFS(colForRow, res, 0, n);
        return res;
    }
    
    void DFS(vector<int>& colForRow, int& count, int row, int n) {
        if (row == n) {
            count += 1;
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!isValid(colForRow, row, i)) continue;
            colForRow[row] = i;
            DFS(colForRow, count, row + 1, n);
        }
    }
    
    bool isValid(vector<int>& colForRow, int row, int col) {
        for (int i = row - 1; i >= 0; i--) {
            int j = colForRow[i];
            if (col == j) return false;
            if (abs(row - i) == abs(col - j)) return false;
        }
        return true;
    }    
};