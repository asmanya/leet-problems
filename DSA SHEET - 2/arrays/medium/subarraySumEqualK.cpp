#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), currentSum, count = 0;
        for(int i = 0; i < n-1; i++)
        {
            currentSum = nums[i];
            for(int j = 0; j < n; j++)
            {
                currentSum += nums[j];
                if (currentSum < k)
                {
                    continue;
                }
                else if (currentSum == k)
                {
                    count++;
                }
                else
                {
                    currentSum = 0;
                    break;
                }
            }
        }
        if(nums[n-1] == k)
        {
            count++;
        }
        return count;
    }
};