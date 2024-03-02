#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size(), left = 0, right = n-1, i = n-1;

        vector<int> res(n);

        while(left < right) {
            int r = abs(nums[right]), l = abs(nums[left]);

            if(r > l){
                res[i] = r*r;
                right--;
            }
            else {
                res[i] = l*l;
                left++;
            }
            i--;
        }

        res[0] = nums[left] * nums[left];

        return res;
    }
};