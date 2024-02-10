#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int f(int ind, int last, vector<int>& nums, vector<vector<int>>& dp) {
        if(ind == nums.size()) return 0;

        if(dp[ind][last + 1] != -1) return dp[ind][last + 1];

        int len = f(ind + 1, last, nums, dp);
        if(last == -1 || nums[ind] > nums[last]) {
            len = max(len, 1 + f(ind + 1, ind, nums, dp));
        }
        return dp[ind][last + 1] = len;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));

        return f(0, -1, nums, dp);
    }
};

