#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0, count = 0, n = nums.size(), i;
        for(i = 0; i< n; i++)
        {
            if(count < 1)
            {
                if(nums[i] != 0)
                {
                    nums[k] = nums[i];
                    k++;
                }
                else if(nums[i] == 0)
                {
                    count++;
                }
            }
            else
            {
                if(nums[i] != 0)
                {
                    nums[k] = nums[i];
                    nums[i] = 0;
                    k++;
                }
            }
        }
    }
};