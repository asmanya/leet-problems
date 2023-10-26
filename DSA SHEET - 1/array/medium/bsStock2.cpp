#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = prices[0], n = prices.size(), max_profit = INT_MIN;
        for(int i = 1; i < n; i++)
        {
            max_profit = max(max_profit, prices[i] - min_price);
            if(min_price > prices[i])
            {
                min_price = prices[i];
            }
        }
        if(max_profit > 0)
        {
            return max_profit;
        }
        return 0;
    }
};