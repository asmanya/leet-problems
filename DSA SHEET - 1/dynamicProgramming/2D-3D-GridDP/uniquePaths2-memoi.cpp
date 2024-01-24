#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int paths(int indx, int indy, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp) {
        if(obstacleGrid[indx][indy] == 1) return 0;
        if(indx == 0 || indy == 0) return 1;
        if(dp[indx][indy] != -1) return dp[indx][indy];

        int first, second;
        if(indx >= 0) {
            first = paths(indx-1, indy, obstacleGrid, dp);
        }
        if(indy >= 0) {
            second = paths(indx, indy- 1, obstacleGrid, dp);
        }
        return dp[indx][indy] = first + second;
    }
    
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return paths(m-1, n-1, obstacleGrid, dp);
    }
};