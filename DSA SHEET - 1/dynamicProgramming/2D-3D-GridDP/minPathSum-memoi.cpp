#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int sum(int indx, int indy, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(indx == 0 && indy == 0) return grid[0][0];
        if(dp[indx][indy] != -1) return dp[indx][indy];

        int up = INT_MAX, left= INT_MAX;

        if(indx > 0)  {
            up = grid[indx][indy] + sum(indx-1, indy, grid, dp);
        }
        if(indy > 0) {
            left = grid[indx][indy] + sum(indx, indy -1, grid, dp);
        }
        return dp[indx][indy] = min(up, left);
    }
    
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return sum(n-1, m-1, grid, dp);
    }
};