#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// upper_bound and lower_bound uses Binary Search 

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> result = {-1, -1};

        if(n == 0)
        {
            return result;
        }

        int left = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(left < n && nums[left] == target)
        {
            int right = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
            result[0] = left;
            result[1] = right;
        }
        return result;
    }
};