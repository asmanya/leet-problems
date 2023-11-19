#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    // creating arrays using stack - RTL Stack
    vector<int> createRTL(vector<int> height, vector<int>& RTL) {
        int num = height.size();
        stack<int> stk;
        for(int i = num - 1; i >= 0; i--) {
            while(!stk.empty() && height[i] >= stk.top()) {
                stk.pop();
            }
            if(stk.empty()) {
                RTL[i] = -1;
            }
            else {
                RTL[i] = stk.top();
            }
            if(i == num - 1) {
                    stk.push(height[num - 1]);
            }
            if(stk.empty() || height[i] > stk.top()) {
                stk.push(height[i]);
            }
        }
        return RTL;
    }

    // creating arrays using stack - LTR Stack
    vector<int> createLTR(vector<int> height, vector<int>& LTR) {
        int num = height.size();
        stack<int> stk;
        for(int i = 0; i < num; i++) {
            while(!stk.empty() && height[i] >= stk.top()) {
                stk.pop();
            }
            if(stk.empty()) {
                LTR[i] = -1;
            }
            else {
                LTR[i] = stk.top();
            }
            if(i == 0) {
                    stk.push(height[0]);
            }
            if(stk.empty() || height[i] > stk.top()) {
                stk.push(height[i]);
            }
        }
        return LTR;
    }

public:
    int trap(vector<int>& height) {
        int num = height.size();
        vector<int> RTL(num, 0);
        vector<int> LTR(num, 0);
        vector<int> ans(num, 0);
        int totalWater = 0;
        
        // creating arrays using monotonic stack
        createRTL(height, RTL);
        createLTR(height, LTR);

        for(int i = 0; i < num; i++) {
            int RTLnum = RTL[i];
            int LTRnum = LTR[i];
            if(RTLnum == -1 || LTRnum == -1) {
                ans[i] = 0;
            }
            else {
                int ref = min(RTLnum, LTRnum) - height[i];
                ans[i] = max(ref, 0);
            }
        }
        for(auto &num : ans){
            totalWater += num;
        }
        return totalWater;
    }
};