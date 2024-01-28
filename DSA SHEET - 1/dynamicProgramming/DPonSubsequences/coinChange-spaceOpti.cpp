#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        if (amount == 0) return 0;
        vector<int> prev(amount + 1, 0);

        for (int target = 1; target <= amount; target++) {
            prev[target] = (target % coins[0] == 0) ? target / coins[0] : 1e9;
        }

        for (int ind = 1; ind < n; ind++) {
            vector<int> curr(amount + 1, 0);
            for (int target = 1; target <= amount; target++) {
                int notTake = prev[target];
                int take = (coins[ind] <= target) ? 1 + curr[target - coins[ind]] : 1e9;

                curr[target] = min(take, notTake);
            }
            prev = curr;
        }

        int res = prev[amount];
        if (res >= 1e9) {
            return -1;
        }

        return res;
    }
};
