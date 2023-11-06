#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> helper(vector<int>& nums, vector<int> temp, int i) {
        if(i == nums.size()) {
            ans.push_back(temp);
            return ans;
        }
        temp.push_back(nums[i]);
        helper(nums, temp, i+1);
        temp.pop_back();
        helper(nums,temp, i+1);
        return ans;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        helper(nums, temp, 0);
        sort(ans.begin(), ans.end());
        return ans;
    }
};