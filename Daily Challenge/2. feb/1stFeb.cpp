#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();

        int pairs = n / 3;
        vector<vector<int>> res(pairs);

        if(n < 3) return {};
        if(n % 3 != 0) return {};
        
        sort(nums.begin(), nums.end());

        for(int p = 0; p < pairs; p++) {
            for(int i = 3 * p; i < 3 * (p + 1) - 1; i++) {
                if(nums[i + 1] - nums[i] > k) {
                    return {};
                }
                res[p].push_back(nums[i]);
            }
            if(nums[3 * (p + 1) - 1] - nums[3 * p] > k) {
                return {};
            }
            res[p].push_back(nums[3 * (p + 1) - 1]);
        }

        return res;
    }
};