#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0, countZeros = 0, len = 0;
        while(right < nums.size()) {
            if (nums[right] == 0) {
                countZeros++;
            }
            while (countZeros > k) {
                if (nums[left] == 0) {
                    countZeros--;
                }
                left++;
            }
            len = max(len, right - left + 1);
            right++;
        }
        return len;
    }
};