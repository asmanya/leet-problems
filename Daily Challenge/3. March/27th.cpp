#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0, right = 0, count = 0, mul = 1;

        if(k <= 1) return 0; 

        while(right < nums.size()) {
            mul *= nums[right];
            while(mul >= k) {
                mul /= nums[left];
                left++;
            }
            count += right - left + 1;
            right++; 
        }

        return count;
    }
};