#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        if (amount == 0) return 0;
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        for (int target = 1; target <= amount; target++) {
            dp[0][target] = (target % coins[0] == 0) ? target / coins[0] : 1e9;
        }

        for (int ind = 1; ind < n; ind++) {
            for (int target = 1; target <= amount; target++) {
                int notTake = dp[ind - 1][target];
                int take = (coins[ind] <= target) ? 1 + dp[ind][target - coins[ind]] : 1e9;

                dp[ind][target] = min(take, notTake);
            }
        }

        int res = dp[n - 1][amount];
        if (res >= 1e9) {
            return -1;
        }

        return res;
    }
};
