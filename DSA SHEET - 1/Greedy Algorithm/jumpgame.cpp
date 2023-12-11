#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = nums[0], i = 0;
        while(i <= maxReach && i <= nums.size()) {
            maxReach = max(maxReach, i + nums[i]);
            if(maxReach >= nums.size() - 1) {
                return true;
            }
            i++;
        }
        return i == nums.size();
    }
};