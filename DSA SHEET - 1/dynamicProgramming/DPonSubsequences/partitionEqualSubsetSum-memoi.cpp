#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool f(int ind, int target, vector<int>& nums, vector<int>& dp) {
        if(target == 0) return true;
        if(ind == 0) return (nums[0] == target);
        if(dp[target] != -1) return dp[target];

        bool notTake = f(ind - 1, target, nums, dp);
        bool take = false;
        if(nums[ind] <= target) {
            take = f(ind -1, target - nums[ind], nums, dp);
        }
        return dp[target] = take || notTake;
    }
    
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;

        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }

        if(sum % 2 == 1) return false;

        vector<int> dp(sum/2+1, -1);
        return f(n-1, sum/2, nums, dp);
    }
};