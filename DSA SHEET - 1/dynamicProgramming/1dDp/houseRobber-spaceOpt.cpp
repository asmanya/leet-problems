#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0], prev2 = 0, curr = 0;
        
        for(int i = 1; i < n; i++) {
            int take = nums[i];
            if(i > 1) take += prev2;
            int notTake = prev;

            curr = max(take, notTake);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};