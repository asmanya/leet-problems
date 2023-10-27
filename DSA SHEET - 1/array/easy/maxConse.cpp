#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        vector<int> count;
        int numCount = 0, n = nums.size(), max = 0;

        for(int i = 0; i < n; i++)
        {
            if(i != n-1)
            {
                if(nums[i] != 0)
                {
                    numCount++;
                }
                else
                {
                    if(numCount != 0)
                    {
                        count.push_back(numCount);
                        numCount = 0;
                    }
                }
            }
            else
            {
                if(nums[i] != 0)
                {
                    numCount++;
                }
                
                if(numCount != 0)
                {
                    count.push_back(numCount);
                } 
            }
        }
        for(auto it = count.begin(); it != count.end(); it++)
        {
            if(*it > max)
            {
                max = *it;
            }
        }
        return max;
    }
};