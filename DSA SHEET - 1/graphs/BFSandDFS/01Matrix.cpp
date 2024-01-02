#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> res(n, vector<int>(m, 0));

        queue<pair<pair<int,int>, int>> q;
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {
                if(mat[row][col] == 0) {
                    res[row][col] = 0;
                    q.push({{row, col}, 0});
                    vis[row][col] = 1;
                }
            }
        }

        int dir[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
        while(!q.empty()) {
            int currRow = q.front().first.first;
            int currCol = q.front().first.second;
            int dis = q.front().second;
            q.pop();

            for(int d = 0; d < 4; d++) {
                int newRow = currRow + dir[d][0];
                int newCol = currCol + dir[d][1];

                if(newRow >=0 && newRow < n && newCol >= 0 && newCol < m && !vis[newRow][newCol]) {
                    res[newRow][newCol] = dis + 1;
                    q.push({{newRow, newCol}, dis + 1});
                    vis[newRow][newCol] = 1;
                }
            }
        }
        return res;
    }
};