#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size(), rotationCount = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i]>nums[(i + 1) % n])
            {
                rotationCount++;
            }
        }
        if(rotationCount > 1)
        {
            return false;
        }
    return true;
    }
};