#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int, int> prefixSumCount;
        int count = 0;
        int sum = 0;

        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            if (sum == goal) {
                count++;
            }
            if (prefixSumCount.count(sum - goal)) {
                count += prefixSumCount[sum - goal];
            }
            prefixSumCount[sum]++;
        }

        return count;
    }
};