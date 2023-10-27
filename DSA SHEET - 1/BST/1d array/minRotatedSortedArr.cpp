#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1, mid;
        while(high >= low)
        {
            mid = ( low + high ) >> 1;
            
            while(nums[mid] < nums[low] && nums[mid] < nums[high])
            {
                low++;
                high--;
            }

            if(nums[low] < nums[high])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return nums[mid];
    }
};
