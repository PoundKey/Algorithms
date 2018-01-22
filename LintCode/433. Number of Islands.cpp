class Solution {
public:
    int numIslands(vector<vector<bool>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int res = 0, m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!grid[i][j] || visited[i][j]) continue;
                res += 1;
                DFS(grid, visited, i, j);
            }
        }
        return res;
    }
    
    void DFS(vector<vector<bool>>& grid, vector<vector<bool>>& visited, int i, int j) {
        if (i < 0 || i >= grid.size()) return;
        if (j < 0 || j >= grid[0].size()) return;
        if (!grid[i][j] || visited[i][j]) return;
        visited[i][j] = true;
        DFS(grid, visited, i, j + 1);
        DFS(grid, visited, i, j - 1);
        DFS(grid, visited, i + 1, j);
        DFS(grid, visited, i - 1, j);
    }
};
