#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
         int n = nums.size();
         long long max = LLONG_MIN, sum = 0, temp;
        vector<long long> a, b;

        for(int i = 0; i < n; i++)
        {
            temp = static_cast<long long>(nums[i]);
            if(max < temp)
            {
                max = temp;
            }
            a.push_back(nums[i]+max);
        }
        for(auto it = a.begin(); it != a.end(); it++)
        {
            sum += *it;
            b.push_back(sum);
        }
        return b;
    }
};
