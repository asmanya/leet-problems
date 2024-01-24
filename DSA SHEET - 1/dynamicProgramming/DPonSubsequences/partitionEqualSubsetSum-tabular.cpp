#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        if(n == 1 || n == 0) return false;

        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }
        if(sum % 2 == 1) return false;

        // tabulation starts here
        int targetSum = sum/2;
        for(int i = 0; i < n; i++) {
            if(nums[i] > targetSum) {
                return false;
            }
        }
        
        vector<vector<bool>> dp(n, vector<bool>(targetSum + 1, false));

        for(int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;

        for(int ind = 1; ind < n; ind++) {
            for(int target = 1; target <= targetSum; target++) {
                bool notTake = dp[ind - 1][target];
                bool take = false;
                if(nums[ind] <= target) {
                    take = dp[ind -1][target - nums[ind]];
                }
                dp[ind][target] = take || notTake;
            }
        }

        return dp[n-1][targetSum];
    }
};