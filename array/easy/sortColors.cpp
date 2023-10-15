#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int temp, n = nums.size();
        for(int i = 0; i < n-1; i++)
        {
            for(int j = i+1 ; j < n; j++)
            {
                if(nums[i] > nums[j])
                {
                    temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                }
            }
        }
    }
};