#include<bits/stdc++.h>
using namespace std;

// Boyer Moore Voting Algorithm

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int key = nums[0], count = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == key) {
                count++;
            }
            else {
                count--;
            }

            if(count == 0) {
                key = nums[i];
                count = 1;
            }
        }
        return key;
    }
};