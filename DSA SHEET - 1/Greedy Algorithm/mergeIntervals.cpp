#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        int n = intervals.size();

        res.push_back(intervals[0]);
        for(int i = 0; i < n; i++) {
            if(intervals[i][0] > res.back()[1]) {
                res.push_back(intervals[i]);
            }
            else {
                res.back()[0] = min(res.back()[0], intervals[i][0]);
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
        }
        return res;
    }
};