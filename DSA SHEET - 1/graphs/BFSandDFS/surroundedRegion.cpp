#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& vis) {
        vis[row][col] = 1;

        int n = board.size();
        int m = board[0].size();

        int dir[4][2] = {{1,0}, {0, 1}, {0, -1}, {-1, 0}};
        for(int d = 0; d < 4; d++) {
            int newRow = row + dir[d][0];
            int newCol = col + dir[d][1];
            if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && !vis[newRow][newCol] && board[newRow][newCol] == 'O') {
                dfs(newRow, newCol, board, vis);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0; i < m; i++) {
            if(!vis[0][i] && board[0][i] == 'O') {
                dfs(0, i, board, vis);
            }
            if(!vis[n-1][i] && board[n-1][i] == 'O') {
                dfs(n-1, i, board, vis);
            }
        }
        for(int i = 0; i < n; i++) {
            if(!vis[i][0] && board[i][0] == 'O') {
                dfs(i, 0, board, vis);
            }
            if(!vis[i][m-1] && board[i][m-1] == 'O') {
                dfs(i, m-1, board, vis);
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};