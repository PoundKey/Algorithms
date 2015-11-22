// Thoughts: Classic Backtracking, just classic. NP.
// Use a colForRow vector to keep track of in which col that the Q is placed in a given row.
// Also it's important to keep track of current row by using a row parameter.
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> sol;
        vector<int> colForRow(n);
        DFS(res, sol, colForRow, 0, n);
        return res;
    }
    
    void DFS(vector<vector<string>>& res, vector<string>& sol, vector<int>& colForRow, int row, int n) {
        if (row == n) {
            res.push_back(sol);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!isValid(colForRow, row, i)) continue;
            colForRow[row] = i;
            string str = genStr(i, n);
            sol.push_back(str);
            DFS(res, sol, colForRow, row + 1, n);
            sol.pop_back();
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
    
    string genStr(int col, int n) {
        string res = "";
        for (int i = 0; i < n; i++) {
            res += (col == i ? 'Q' : '.');
        }
        return res;
    }
};