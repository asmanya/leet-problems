#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<long> prev(amount + 1, 0); 

        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0)
                prev[i] = 1;
        }

        for (int ind = 1; ind < n; ind++) {
            vector<long> curr(amount + 1);
            for (int target = 0; target <= amount; target++) {
                long notTaken = prev[target];

                long taken = 0;
                if (coins[ind] <= target)
                    taken = curr[target - coins[ind]];

                curr[target] = notTaken + taken;
            }

            prev = curr;
        }

        return prev[amount];
    }
};
