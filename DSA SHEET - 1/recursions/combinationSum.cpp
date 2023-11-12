#include<iostream>
#include<vector>
using namespace std;

class Solution {
private: 
    void findCombination(int idx, int target, vector<int>& ds, vector<int>& arr, vector<vector<int>>& ans) {
        if(idx == arr.size()) {
            if(target == 0) {
                ans.push_back(ds);
            }
            return;
        }
        // picking element
        if(arr[idx] <= target) {
            ds.push_back(arr[idx]);
            findCombination(idx, target - arr[idx], ds, arr, ans);
            ds.pop_back();
        }
        findCombination(idx + 1, target, ds, arr, ans);
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0 ,target, ds, candidates, ans);
        return ans;
    }
};