#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, h = n-1, mid;
        while( l < h)
        {
            mid = (l + h) / 2;
            if(nums[mid] < target)
            {
                l = mid + 1;
            }
            else if(nums[mid] > target)
            {
                h = mid - 1;
            }    
            else if(nums[mid] == target)
            {
               return mid;
            }
        }
        if(l == h || l == mid)
        {
            if(target < nums[l])
            {
                return l;
            }
            else if(target == nums[l])
            {
                return l;
            }
        }
        return l + 1;
    }
};
