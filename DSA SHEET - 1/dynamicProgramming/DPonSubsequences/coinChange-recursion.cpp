#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int minCoin(int ind, int target, vector<int>& coins) {
        if(ind == 0) {
            if(target % coins[0] == 0) return target/ coins[0];
            return 1e9;
        }

        int notTake = minCoin(ind- 1, target, coins);
        int take = INT_MAX;
        if(coins[ind] <= target) {
            take = 1 + minCoin(ind, target - coins[ind], coins);
        }

        return min(take, notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        if(amount == 0) return 0;
        int res = minCoin(n-1, amount, coins);
        if(res >= 1e9) {
            return -1;
        }

        return res;
    }
};