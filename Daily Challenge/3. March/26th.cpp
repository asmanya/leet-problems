#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            if(nums[i] < 0)
                nums[i] = 0;
        }

        for(int i = 0; i < n; i++) {
            int x = abs(nums[i]);

            if(x == 0 || x > n) continue;

            if(nums[x-1] < 0) continue;
            else if(nums[x-1] > 0) nums[x-1] *= -1;
            else nums[x-1] = -(n + 2);
        }

        int i;
        for(i = 1; i <= n; i++) {
            if(nums[i-1] >= 0) return i;
        }

        if(i == n+1) return n+1;

        return n;
    }
};