#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int f(int ind, int buy, int times, vector<int>& prices, vector<vector<vector<int>>>& dp) {
        int n = prices.size();
        if(ind == n || times == 0) return 0;

        if(dp[ind][buy][times] != -1) return dp[ind][buy][times];

        int profit = 0;
        if(buy) {
            profit = max(-prices[ind] + f(ind + 1, 0, times, prices, dp), f(ind + 1, 1, times, prices, dp));
        } else {
            profit = max(prices[ind] + f(ind + 1, 1, times - 1, prices, dp), f(ind + 1, 0, times, prices, dp));
        }
        return dp[ind][buy][times] = profit;
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return f(0, 1, 2, prices, dp);
    }
};
