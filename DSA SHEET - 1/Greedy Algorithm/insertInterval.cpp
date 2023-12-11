#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> res;
        if(n == 0) {
            res.push_back(newInterval);
        }
        else {
            int i = 0;
            while(i < n && intervals[i][1] < newInterval[0]) {
                res.push_back(intervals[i++]);
            }
            vector<int> merge = newInterval;
            while(i < n && merge[1] >= intervals[i][0]){
                merge[0] = min(merge[0], intervals[i][0]);
                merge[1] = max(merge[1], intervals[i++][1]);
            }
            res.push_back(merge);
            while(i < n) {
                res.push_back(intervals[i++]);
            }
        }
        return res;
    }
};