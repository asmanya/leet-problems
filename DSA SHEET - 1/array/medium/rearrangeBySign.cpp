#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size(), k = 0, j = 0;
        vector<int> result(n,0);
        for(int i = 0; i < n; i++)
        {
            if(nums[i] > 0)
            {
                result[2 * k] = nums[i];
                k = k + 1;
            }
            else if(nums[i] < 0)
            {
                result[2 * j + 1] = nums[i];
                j = j + 1;
            }
        }
        return result;
    }
};