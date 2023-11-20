#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> stk;
        int size = nums.size();
        vector<int> ans(size, 0);
        for(int i = 2 * size-1; i >= 0; i--) {
            while(!stk.empty() && nums[i % size] >= stk.top()) {
                stk.pop();
            }
            if(stk.empty()){
                ans[i % size] = -1;
            }
            else {
                ans[i % size] = stk.top();
            }
            stk.push(nums[i % size]);
        }
        return ans;
    }
};