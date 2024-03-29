#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kInversePairs(int n, int k) {
        const int MOD = 1e9 + 7;

        // Initialize the 2D DP array
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        dp[0][0] = 1;

        // Populate the DP array
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) {
                for (int l = 0; l <= min(j, i - 1); ++l) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - l]) % MOD;
                }
            }
        }

        return dp[n][k];
    }
};