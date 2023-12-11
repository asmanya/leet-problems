#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long n = nums.size();
        long long maxi = *max_element(nums.begin(), nums.end());
        long long ans = 0, count = 0, i = 0, j = 0;
        
        for(j = 0; j < n; j++) {
            if(nums[j] == maxi) {
                count++;
            }
            if(count >= k) {
                for(; count >= k; i++) {
                    ans += n-j;
                    if(nums[i] == maxi) {
                        count--;
                    }
                }
            }
        }
        return ans;
    }
};
