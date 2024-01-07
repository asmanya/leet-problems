#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        
        vector<unordered_map<long long, int>> dp(n);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long long diff = static_cast<long long>(nums[i]) - nums[j];

                dp[i][diff] += 1;

                if (dp[j].count(diff)) {
                    result += dp[j][diff];
                    dp[i][diff] += dp[j][diff];
                }
            }
        }

        return result;
    }
};