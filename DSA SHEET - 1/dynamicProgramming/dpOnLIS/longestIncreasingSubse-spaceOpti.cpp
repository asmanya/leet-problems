#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> ahead(n + 1, 0), cur(n+1, 0);

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int last = ind - 1; last >= -1; last--) {
                int len = ahead[last + 1]; 
                if (last == -1 || nums[ind] > nums[last]) {
                    len = max(len, 1 + ahead[ind + 1]);
                }
                cur[last + 1] = len;
            }
            ahead = cur;
        }

        return cur[0];
    }
};
