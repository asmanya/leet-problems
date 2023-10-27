#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> umap;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            umap[nums[i]]++;
        }
        for(auto& u : umap)
        {
            if(u.second > n/2)
            {
                return u.first;
            }
        }
        return 0;
    }
};