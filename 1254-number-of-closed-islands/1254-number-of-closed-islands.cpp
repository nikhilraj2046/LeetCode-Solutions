class Solution {
private:
    bool dfs(vector<vector<int>>& grid, int i, int j, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m) {
            return false;
        }
        if (grid[i][j] == -1 || grid[i][j] == 1)
            return true;
        grid[i][j] = -1;
        bool down = dfs(grid, i + 1, j, n, m);
        bool up = dfs(grid, i - 1, j, n, m);
        bool right = dfs(grid, i, j + 1, n, m);
        bool left = dfs(grid, i, j - 1, n, m);
        return down && up && right && left;
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0 && dfs(grid, i, j, n, m))
                    count++;
            }
        }
        return count;
    }
};