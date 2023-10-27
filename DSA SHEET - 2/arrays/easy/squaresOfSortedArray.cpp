#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res;
        for(int &num : nums)
        {
            int sqr = pow(num, 2);
            res.push_back(sqr);
        }
        sort(res.begin(), res.end());
        return res;
    }
};