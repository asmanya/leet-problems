#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> res;
        unordered_map<int, int> umap;

        int row = 0;
        for(int i = 0; i < nums.size(); i++) {
            row = umap[nums[i]];
            if(row >= res.size()) {
                res.push_back({nums[i]});
            }
            else {
                res[row].push_back(nums[i]);
            }
            umap[nums[i]]++;
        }

        return res;
    }
};