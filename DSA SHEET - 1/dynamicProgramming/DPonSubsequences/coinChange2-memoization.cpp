#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int ways(int ind, int target, vector<int>& coins, vector<vector<int>>& dp) {
        if (ind == coins.size() - 1) {
            return (target == 0 || target % coins[ind] == 0) ? 1 : 0;
        }
        if (target == 0) return 1;
        if(dp[ind][target] != -1) return dp[ind][target];

        int notPick = ways(ind + 1, target, coins, dp);
        int pick = 0;
        
        if (coins[ind] <= target) {
            pick = ways(ind, target - coins[ind], coins, dp);
        }

        return dp[ind][target] = notPick + pick;
    }

public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return ways(0, amount, coins, dp);
    }
};
