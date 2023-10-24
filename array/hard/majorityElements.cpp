#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> umap;
        vector<int> a;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            umap[nums[i]]++;
        }
        for(auto &key : umap)
        {
            if(key.second > n/3)
            {
                a.push_back(key.first);
            }
        }
        return a;
    }
};