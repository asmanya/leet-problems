#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int sum = 0;
        vector<int> res;
        for( int&num : nums)
        {
            sum += num;
            res.push_back(sum);
        }
    return res;
    }
};