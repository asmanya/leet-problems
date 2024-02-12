#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

        for(int i = 0; i <= n; i++) {
            for(int j = 0; j < k+1; j++) {
                dp[i][0][j] = 0;
            }
        }

        for(int ind = n - 1; ind >= 0; ind--) {
            for(int buy = 1; buy >= 0; buy--) {
                for(int times = k; times >= 0; times--) {
                    int profit = 0;
                    if(buy) {
                        profit = max(-prices[ind] + dp[ind + 1][0][times], dp[ind + 1][1][times]);
                    } else {
                        if(times > 0)
                            profit = max(prices[ind] + dp[ind + 1][1][times - 1], dp[ind + 1][0][times]);
                        else profit = dp[ind + 1][0][times];
                    }
                    dp[ind][buy][times] = profit;
                }
            }
        }
        
        return dp[0][1][k];
    }
};