#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int sm, bg, mid;
        sm = 0;
        bg = nums.size() - 1;
        while(sm <= bg)
        {
            mid = (sm + bg) / 2;
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] < target)
            {
                sm = mid + 1;
            }
            else
            {
                bg = mid - 1;
            }
        }
        return -1;
    }
};