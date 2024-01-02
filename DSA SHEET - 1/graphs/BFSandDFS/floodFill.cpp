#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& image, int color, int val) {
        vis[row][col] = 1;
        
        int n = image.size();
        int m = image[0].size();

        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for(int d = 0; d < 4; d++) {
            int newRow = row + dir[d][0];
            int newCol = col + dir[d][1];
            if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && !vis[newRow][newCol] && image[newRow][newCol] == val) {
                image[newRow][newCol] = color;
                vis[newRow][newCol] = 1;
                dfs(newRow, newCol, vis, image, color, val);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int val = image[sr][sc];
        image[sr][sc] = color;
        dfs(sr, sc, vis, image, color, val);
        return image;
    }
};