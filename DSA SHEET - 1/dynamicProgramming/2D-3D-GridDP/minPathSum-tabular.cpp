#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m));

        dp[0][0] = grid[0][0];
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 && j == 0) continue;
                
                int first, second;
                if(i > 0)  {
                    first = grid[i][j] + dp[i-1][j];
                }
                if(j > 0) {
                    second = grid[i][j] + dp[i][j-1];
                }
                dp[i][j] = (i == 0) ? second : (j == 0) ? first : min(first, second);
            }
        }

        return dp[n-1][m-1];
    }
};