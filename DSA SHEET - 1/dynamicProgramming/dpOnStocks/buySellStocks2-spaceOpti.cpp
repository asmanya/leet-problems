#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> cur(2, 0), ahead(2, 0), ahead2(2, 0);

        int profit;
        for(int ind = n-1; ind >= 0; ind--) {
            for(int buy = 0; buy < 2; buy++) {
                if(buy) {
                    profit = max(-prices[ind] + ahead[0], ahead[1]);
                } else {
                    profit = max(prices[ind] + ahead2[1], ahead[0]);
                }
                cur[buy] = profit;
            }
            ahead2 = ahead;
            ahead = cur;
        }

        return cur[1];
    }
};