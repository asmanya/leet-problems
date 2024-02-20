#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums) {
        
        int flag = nums[1] + nums[0], count = 1, n = nums.size();
        
        for(int i = 3; i < n; i += 2){
            if(nums[i] + nums[i-1] == flag) count++;
            else break;
        }
        return count;
    }
};