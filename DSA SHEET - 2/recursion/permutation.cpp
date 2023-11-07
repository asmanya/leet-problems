#include<iostream>
#include<vector>
using namespace std;

class Solution1 {
private:
    void helper(vector<vector<int>>& ans, vector<int>& nums, vector<int>& temp, int map[]) {
        if(temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(!map[i]) {
                temp.push_back(nums[i]);
                map[i] = 1;
                helper(ans, nums, temp, map);
                map[i] = 0;
                temp.pop_back();
            }
        }

    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int map[nums.size()];
        for(int i = 0; i < nums.size(); i++) {
            map[i] = 0;
        }
        helper(ans, nums, temp, map);
        return ans; 
    }
};

class Solution2 {
private:
    void helper(int index, vector<int>& nums, vector<vector<int>>& ans) {
        if(index == nums.size()) {
            ans.push_back(nums);
            return;
        }
        for(int i = index; i < nums.size(); i++) {
            swap(nums[index], nums[i]);
            helper(index + 1, nums, ans);
            swap(nums[index], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(0, nums, ans);
        return ans;
    }
};