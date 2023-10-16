#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> a;
        int max_diff = INT_MIN, diff, max = INT_MIN, n = prices.size();
        for(int i = n-1; i > 0; i--)
        {
            for(int j = i-1; j > -1; j--)
            {
                diff = prices[i] - prices[j];
                if(diff > max_diff)
                {
                    max_diff = diff;
                }
            }
            a.push_back(max_diff);
            max_diff = INT_MIN;
        }
        for(auto &num : a)
        {
            if(num > max)
            {
                max = num;
            }
        }
        if(max > 0)
        {
            return max;
        }
        return 0;
    }
};