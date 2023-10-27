#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
      int totalSum = 0;  
      int currentSum = 0;  

      for(int &num : nums)
      {
          totalSum += num;
      }

      for(int i = 0; i < nums.size(); i++)
      {
          if(currentSum == totalSum - currentSum - nums[i])
          {
              return i;
          }
          currentSum += nums[i];
      }
      return -1;
    }
};