#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), index;
        vector<int> hash(n+1, 0);
        for(int i = 0; i < n; i++)
        {
            index = nums[i];
            hash[index] += 1;
        }
        for(int i = 0; i < n+1; i++)
        {
            if(hash[i] == 0)
            {
                return i;
            }
        }
        return -1;
    }
};