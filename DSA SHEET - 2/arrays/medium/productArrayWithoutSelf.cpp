#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int front = 1, back = 1, n = nums.size();
        vector<int> forwardMul, backMul(n, 0), res(n , 0);

        for(int i = 0; i < n; i++)
        {
            front *= nums[i];
            forwardMul.push_back(front);
        }

        for(int j = n-1; j > -1; j--)
        {
            back *= nums[j];
            backMul[j] = back;
        }

        res[0] = backMul[1];
        res[n-1] = forwardMul[n-2];
        for(int i = 1; i < n-1; i++)
        {
            res[i] = forwardMul[i-1] * backMul[i+1];
        }
    return res;
    }
};