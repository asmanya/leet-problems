#include<bits/stdc++.h>
using namespace std;

// KADANE'S ALGORITHM

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = nums[0], maxSum = nums[0], n = nums.size();
        for(int i = 1; i < n; i++) {
            currentSum = max(nums[i], nums[i] + currentSum);
            maxSum = max(maxSum, currentSum);
        }
        return maxSum;
    }
};