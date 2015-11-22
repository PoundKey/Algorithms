// Thoughts: count++ if A[i][j] = '1', and then flood each connected '1' with '2', 
// spread to 4 directions. Runtime: O(n)
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j ++) {
                if (grid[i][j] != '1') continue;
                count++;
                DFS(grid, i, j);
            }
        }
        return count;
    }
    
    void DFS(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return;
        if (grid[i][j] != '1') return;
        grid[i][j] = '2';
        DFS(grid, i + 1, j);
        DFS(grid, i - 1, j);
        DFS(grid, i, j + 1);
        DFS(grid, i, j - 1);
    }
};