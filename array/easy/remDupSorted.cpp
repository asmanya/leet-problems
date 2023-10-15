#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), max = nums[n-1], temp;
        
        if (n <= 1) {
            return n;
        }
        
        for(int i = n-1 ; i >= 1; i--)
        {
            if(nums[i] == nums[i-1])
            {
                for(int j = i; j < n -1 ; j++)
                {
                    temp = nums[j];
                    nums[j] = nums[j+1];
                    nums[j+1] = temp;
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == max)
            {
                return i+1;
            }
        }
    return 0;
    }
};