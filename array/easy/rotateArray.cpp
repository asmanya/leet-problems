#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result(n, 0);
        for(int i = 0; i < n; i++)
        {
            result[(i+k) % n] = nums[i];
        }
        for(int i = 0; i < n; i++)
        {
            nums[i] = result[i];
        }
    }
};