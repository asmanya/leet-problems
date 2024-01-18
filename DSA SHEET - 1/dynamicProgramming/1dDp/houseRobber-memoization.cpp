#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int ways(int ind, vector<int>& nums, vector<int>& dp) {
        if(ind == 0) return nums[0];
        if(ind < 0) return 0;
        if(dp[ind] != -1) return dp[ind];

        int pick = nums[ind] + ways(ind - 2, nums, dp);
        int notPick = ways(ind - 1, nums, dp);

        return dp[ind] = max(pick, notPick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return ways(n-1, nums, dp);
    }
};