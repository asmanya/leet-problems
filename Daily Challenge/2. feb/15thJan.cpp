#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<long long> hash(n);
        hash[0] = nums[0];

        for(int i = 1; i < n; i++) {
            hash[i] = hash[i-1] + nums[i];
        }

        long long peri = -1;
        for(int i = 2; i < n; i++) {
            if(nums[i] < hash[i-1]){
                peri = max(peri, hash[i]);
            }
        }

        return peri;
    }
};