#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;
        vector<int> ans;
        unordered_map<int,int> umap;
        for(int i = nums2.size() -1; i >= 0; i--) {
            while (!stk.empty() && nums2[i] > stk.top()) {
                stk.pop();
            }
            if (stk.empty()) {
                umap[nums2[i]] = -1;
            } else {
                umap[nums2[i]] = stk.top();
            }
            stk.push(nums2[i]);
        }
        for(int i = 0; i < nums1.size(); i++) {
            ans.push_back(umap[nums1[i]]);
        }
        return ans;
    }
};