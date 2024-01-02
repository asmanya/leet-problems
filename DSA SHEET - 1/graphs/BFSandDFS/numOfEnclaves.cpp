#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        vis[row][col] = 1;

        int n = grid.size();
        int m = grid[0].size();
        
        int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        for(int d = 0; d < 4; d++) {
            int newRow = row + dir[d][0];
            int newCol = col + dir[d][1];
            if(newRow >= 0 && newRow < n && newCol >=0 && newCol < m && !vis[newRow][newCol] && grid[newRow][newCol] == 1) {
                dfs(newRow, newCol, grid, vis);
            }
        }
    } 
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0; i < m; i++) {
            if(!vis[0][i] && grid[0][i] == 1) {
                dfs(0, i, grid, vis);
            }
            if(!vis[n-1][i] && grid[n-1][i] == 1) {
                dfs(n-1, i, grid, vis);
            }
        }

        for(int i = 0; i < n; i++) {
            if(!vis[i][0] && grid[i][0] == 1){
                dfs(i, 0, grid, vis);
            }
            if(!vis[i][m-1] && grid[i][m-1] == 1) {
                dfs(i, m-1, grid, vis);
            }
        }

        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && grid[i][j] == 1) {
                    count++;
                }
            }
        }
        return count;
    }
};