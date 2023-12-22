#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis) {
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();

        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for (int d = 0; d < 4; ++d) {
            int newRow = row + directions[d][0];
            int newCol = col + directions[d][1];

            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
            !vis[newRow][newCol] && grid[newRow][newCol] == '1') {
                dfs(newRow, newCol, grid, vis);
            }  
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int count = 0;
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {
                if(!vis[row][col] && grid[row][col] == '1') {
                    dfs(row, col, grid, vis);
                    count++;
                }
            }
        }
        return count;
    }
};