#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> um;
        int maxi = 0;

        for(int i = 0; i < nums.size(); i++) {
            um[nums[i]]++;
            if(um[nums[i]] > maxi) maxi = um[nums[i]];
        }

        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(um[nums[i]] == maxi) res++;
        }

        return res;
    }
};