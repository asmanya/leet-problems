#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int left = 0, right = 0, count = 0, currNum = 0;
        while(right < nums.size()) {
            if(nums[right] % 2 != 0) {
                currNum++;
            }
            while(currNum > k) {
                if(nums[left] % 2 != 0) {
                    currNum--;
                }
                left++;
            }
            if(currNum == k) {
                count++;
                int tempLeft = left;
                while (tempLeft < right && nums[tempLeft] % 2 == 0) {
                    tempLeft++;
                    count++;
                }
            }
            right++;
        }
        return count;
    }
};