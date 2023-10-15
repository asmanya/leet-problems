#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> umap;
        for(int num : nums)
        {
            umap[num]++;
        }
        for(auto &pair : umap)
        {
            if(pair.second == 1)
            {
                return pair.first;
            }
        }
        return 0;
    }
};