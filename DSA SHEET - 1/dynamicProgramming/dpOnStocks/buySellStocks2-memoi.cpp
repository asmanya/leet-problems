#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int f(int ind, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        int n = prices.size();
        if(ind == n) return 0;

        if(dp[ind][buy] != -1) return dp[ind][buy];

        int profit = 0;
        if(buy){
            profit = max(-prices[ind] + f(ind + 1, 0, prices, dp), f(ind + 1, 1, prices, dp));
        } else {
            profit = max(prices[ind] + f(ind + 1, 1, prices, dp), f(ind + 1, 0, prices, dp));
        }
        return dp[ind][buy] = profit;
    }
    
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return f(0, 1, prices, dp);
    }
};