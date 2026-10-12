#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    vector<pair<int, int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void bfs(vector<vector<char>>& grid, int i, int j, queue<pair<int,int>>& que){
        que.push({i, j});
        grid[i][j] = '$'; 
        auto isSafe = [&](int i, int j){
            if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1'){
                return false;
            }
            return true;
        };
        while(!que.empty()){
            auto curr = que.front();
            que.pop();        
            for(auto &p : dir){
                int a = curr.first + p.first;
                int b = curr.second + p.second; 
                if(isSafe(a, b)){
                    que.push({a, b});
                    grid[a][b] = '$';
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        queue<pair<int,int>> que;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    bfs(grid, i, j, que); // Removed the invalid 'd = ' assignment
                    count++;
                }
            }
        }
        return count;
    }
};
