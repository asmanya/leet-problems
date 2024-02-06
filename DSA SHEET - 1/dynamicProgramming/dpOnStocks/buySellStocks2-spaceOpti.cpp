#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> ahead(2), cur(2);

        ahead[0] = 0;
        int profit = 0;

        for(int ind = n-1; ind >= 0; ind--) {
            for(int buy = 0; buy < 2; buy++) {
                if(buy){
                    profit = max(-prices[ind] + ahead[0], ahead[1]);
                } else {
                    profit = max(prices[ind] + ahead[1], ahead[0]);
                }
                cur[buy] = profit;
            }
            ahead = cur;
        }

        return ahead[1];
    }
};