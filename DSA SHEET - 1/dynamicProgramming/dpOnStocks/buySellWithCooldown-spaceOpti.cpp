#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));

        int profit;
        for(int ind = n-1; ind >= 0; ind--) {
            for(int buy = 0; buy <= 1; buy++) {
                if(buy) {
                    profit = max(-prices[ind] + dp[ind+1][0], dp[ind+1][1]);
                } else {
                    profit = max(prices[ind] + dp[ind+2][1], dp[ind+1][0]);
                }
                dp[ind][buy] = profit;
            }
        }

        return dp[0][1];
    }
};