#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 1);

        for(int ind = 0; ind < n; ind++) {
            for(int prev = 0; prev < ind; prev++) {
                if(nums[prev] < nums[ind]) {
                    dp[ind] = max(dp[ind], 1 + dp[prev]);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};